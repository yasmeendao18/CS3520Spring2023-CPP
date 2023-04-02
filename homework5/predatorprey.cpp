#include <iostream>
#include "predatorprey.hpp"
using namespace std; 

// class Game;
// class Doodlebug;
// class Organism;
// class Ant; 


std::ostream& operator<<(std::ostream& os, Game& ga) {
    os<<"Game"<<"\n";
    for(int x = 0; x <ga.getGrid().getWidth();x++){
        for(int y = 0; y<ga.getGrid().getHeight();y++){
            Organism ref;
            cellPos pos = *(new cellPos(x,y));
            if(ga.getOrganismAt(pos,ref)){
                os<<(&ref)->getSymbol();
            }else{
                os<<"-";
            }
        }
        os<<endl;
    };
    return os;
}



bool Grid::inFrame(cellPos p){
    return p.get_x()<this->width&&p.get_y()< this->height&&p.get_x()>0&&p.get_y()>0;
}
typedef class Game;

class Reproduce: public Task{
    private:
        cellPos origin;
        cellPos destination;
        Organism organism;
    public:
        Reproduce(){}
        Reproduce(cellPos origin, cellPos destination, Organism o){
            this->origin = origin;
            this->destination = destination;
            this->organism = o;
        }

        virtual cellPos getOrigin(){return this->origin;}
        virtual cellPos getDestination(){return this->destination;}
        virtual void UpdateGrid(Grid &g,Game &ga);

};

Task Queen::getTask(std::vector<Organism> next){
    vector<cellPos*> movementTasks = {};
    for(int x = -2; x <=2; x++){
        for(int y =-2; y<= 2; y++){
            
            bool in=false;
            for(auto n : next){
                in = n.getPosition().get_x()!=x+this->getPosition().get_x()&&n.getPosition().get_y()!=y+this->getPosition().get_y();
            }
            movementTasks.push_back(new cellPos(x,y));
        }
    }
    if(timeElapsed>25){
        if(this->hasBred){
            //if breeding has been done, it will move aimle
            if(this->timeSinceBreed>=10){
                cellPos availablePosition;
                Organism *newO = new Queen(this->getPosition().get_x(),this->getPosition().get_y());
                Task*t= new Reproduce(this->getPosition(),*movementTasks[0],*newO);
                return *t;
            }
            this->timeSinceBreed++;
        }else{
            int i=0;
            bool found = false;
            for(;i<next.size();i++){
                if(next[i].canMate()){
                    found =true;
                    break;
                }
            }
            if(found){
                Task*t= new Breed(this->getPosition(),next[i].getPosition());
                this->hasBred=true;
                return *t;
            }
        }
    }
    cellPos p = this->getPosition();
    Task*t= new Move(p,p);
    return *t;
}

#define doodlebug_count 15
#define queen_count 1
#define male_count 14
#define female_count 20


void Game::stepOrganism(int i){
            
    Organism t= *(this->getOrganism(i));
    Organism collision= *(new Organism);
    vector<Organism> collisions = {};
    cellPos cpos = t.getPosition();
    
    //check if organisms collide
    for(int x = cpos.get_x()-1;x<cpos.get_x()+2;x++){
        for(int y= cpos.get_y()-1;y<cpos.get_y()+2;y++){
            if(x==cpos.get_x()&&y==cpos.get_y()){
                continue;
            }
            cellPos pos = *(new cellPos(x,y));
            if(getOrganismAt(pos,collision)){
                collisions.push_back(collision);
            }
        }
    }

    Task task = t.getTask(collisions);
    bool isPerformed = grid.inFrame(task.getDestination());
    task.UpdateGrid(this->grid,*this);
   t.performTask(task,isPerformed);
            
}

void Move::UpdateGrid(Grid &g,Game &ga){
    
}
void Breed::UpdateGrid(Grid &g, Game &ga){
    int count = 10;
    for(int x= this->origin.get_x()-2;x<this->origin.get_x()+2;x++){
        for(int y = this->origin.get_y()-2;x<this->origin.get_y()+2;y++){
            int temp;
            cellPos pos = *(new cellPos(x,y));
            if(!ga.getOrganismAt(pos,temp)){
                Organism newOrg = Ant::spawn();
                newOrg.MoveObject(pos);
                ga.addOrganism(&newOrg);
            }
        }
    }
}
void Eat::UpdateGrid(Grid &g, Game &ga){
    cellPos dest = this->destination;
    int ref;
    if(ga.getOrganismAt(dest,ref)){
        ga.removeOrganism(ref);
    }
}
void Reproduce::UpdateGrid(Grid &g,Game &ga){
    ga.addOrganism(&(this->organism));
}

int main(){
    
    Grid *g = new Grid(10,10);

    Queen *queen = new Queen;
    queen->MoveObject(*(new cellPos(0,1)));
    Male *male = new Male;
    male->MoveObject(*(new cellPos(0,2)));
    Female *female=  new Female;
    female->MoveObject(*(new cellPos(2,0)));
    Doodlebug *doodlebug = new Doodlebug;
    vector<Organism*> organisms = {queen,male,female,doodlebug};
    Game *ga = new Game(organisms,*g);
    for(int iter = 0; iter < 400;iter++){
        for(int i =0; i < ga->getOrganismCount();i++){
            ga->stepOrganism(i);
        }
       
        cout<<*ga<<endl;
    }


}