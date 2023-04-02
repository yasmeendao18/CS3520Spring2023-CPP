#include <vector>
#include <random>

// class to get adjacent cell position
class cellPos{
private:
    int x;
    int y;
public:
    cellPos()
    {
        this->x = 0;
        this->y = 0;
    }
   cellPos(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    // overloaded operators
    const cellPos operator+(cellPos &other)
    {
        const cellPos * pptr = new cellPos(this->get_x()+other.get_x(),this->get_y()+other.get_y());
        return  *pptr;
    }
    const cellPos operator-(cellPos &other)
    {
        const cellPos *pptr = new cellPos(this->get_x()-other.get_x(),this->get_y()-other.get_y());
        return  *pptr;
    }
    bool operator==(cellPos &other)
    {
        return this->get_x()==other.get_x()&&this->get_y()==other.get_y();
    }

    int get_x()
    {
        return this->x;
    }
    int get_y()
    {
        return this->y;
    }
    static cellPos randDirection()
    {
        srand(time(NULL));
        int x = (rand()%3) - 1;
        int y = (rand()%3) - 1;
        cellPos* pptr = new cellPos(x,y);
        cellPos _pptr = *pptr;
        return _pptr;
    }
};

// add index
class updateGame
{
    private:
        std::vector<int> add;
        std::vector<int> remove;
    public:
        updateGame()
        {
            add = {};
            remove = {};
        }

        // getters and setters
        int getAddSize()
        {
            return add.size();
        }
        int getRemoveSize()
        {
            return remove.size();
        }
        int getAdd(int i)
        {
            return add[i];
        }
        int getRemove(int i)
        {
            return remove[i];
        }
        void appendAddIndex(int i)
        {
            this->add.push_back(i);
        }
        void appendRemoveIndex(int i)
        {
            this->remove.push_back(i);
        }
};


typedef class Game;

class Grid{
    private:
        int width;
        int height;
    public:
        Grid()
        {
            this->width = 100;
            this->height = 100;
        }
        Grid(int width,int height)
        {
            this->width  =width;
            this->height = height;
        }
        bool inFrame(cellPos position);

        const int getWidth()
        {
            return width;
        }
        const int getHeight()
        {
            return height;
        }

};

class Task{
public:
    virtual void UpdateGrid(Grid &g,Game &ga)
    {
          
    }
    virtual cellPos getOrigin()
    {
        return *(new cellPos);
    }
    virtual cellPos getDestination()
    {
        return *(new cellPos);
    }
    
};

class Move : public Task
{
private:
    cellPos origin;
    cellPos destination;
public:
    Move(){}
    Move(cellPos origin, cellPos destination)
    {
        this->origin = origin;
        this->destination = destination;
    }

    virtual cellPos getOrigin(){return this->origin;}
    virtual cellPos getDestination(){return this->destination;}
    virtual void UpdateGrid(Grid &g,Game&ga);
};

class Breed : public Task
{
private:
    cellPos origin;
    cellPos destination;
public:
    Breed();
    Breed(cellPos origin, cellPos destination)
    {
        this->origin = origin;
        this->destination = destination;
    }

    virtual cellPos getOrigin(){return this->origin;}
    virtual cellPos getDestination(){return this->destination;}
    virtual void UpdateGrid(Grid &g,Game &ga);
    

};

class Eat : public Task
{
private:
    cellPos origin;
    cellPos destination;
public:
    Eat();
    Eat(cellPos origin, cellPos destination)
    {
        this->origin = origin;
        this->destination = destination;
    }

    virtual cellPos getOrigin(){return this->origin;}
    virtual cellPos getDestination(){return this->destination;}
    virtual void UpdateGrid(Grid &g,Game &ga);
    
};


class Organism{
private:
    cellPos position;
    char refchar;
public:

    // tasks for organism
    virtual Task getTask(std::vector<Organism> next){
        Task* t = new Move();
        return *t;
    }
    virtual char getSymbol() const{
        return this->refchar;
    }
    virtual cellPos getPosition(){
        return this->position;
    }
    virtual bool starve(){
        return false;
    }
    virtual bool isEatable(){
        return false;
    }
    virtual bool canMate(){
        return false;
    }
    void MoveObject(cellPos position){
        this->position = position;
    }
    void SetChar(char c){
        this->refchar = c;
    }
    
    virtual void performTask(Task task,bool isPerformed){}
    
};
class Ant:public Organism{
    private:
        int timeSinceMove = 0;
    public:

    Ant()
    {
        this->SetChar('a');
    }
    // organism next to organism
    virtual Task getTask(std::vector<Organism> next)
    {
        cellPos newDest = *(new cellPos(this->getPosition().get_x()+(rand()%2)-1,this->getPosition().get_y()+(rand()%2)-1));
        Task* t = new Move(this->getPosition(),newDest);
        return *t;
    }
    virtual void performTask(Task task,bool isPerformed)
    {
        timeSinceMove++;
        this->MoveObject(task.getDestination());
    }
    virtual void moveCount()
    {
        timeSinceMove=0;
    }
    virtual bool starve()
    {
        return timeSinceMove >=5;
    }
    virtual bool isEatable()
    {
        return true;
    }
    virtual bool canMate()
    {
        return false;
    }
    static Ant spawn();
    virtual char getSymbol() const
    {
        return 'A';
    }
};
class Doodlebug:public Organism
{
    private:
        int timeSinceEat = 0;
    public:

    Doodlebug()
    {
        this->SetChar('D');
    }

    virtual Task getTask(std::vector<Organism> neighbors)
    {
        int i = 0;
        bool found = false;
        for(;i<neighbors.size();i++){
            if(neighbors[i].isEatable()){
                found=true;
                break;
            }
        }
        Task* t;
        if(found)
        {
            t = new Eat(this->getPosition(),neighbors[i].getPosition());
            this->timeSinceEat=0;
        }else{
            this->timeSinceEat++;
            cellPos newDest = *(new cellPos(this->getPosition().get_x()+(rand()%2)-1,this->getPosition().get_y()+(rand()%2)-1));
            Task* t = new Move(this->getPosition(),newDest);
        }
        return *t;
    }
    
    virtual void performTask(Task task,bool isPerformed)
    {
        cellPos origin = task.getOrigin();
        cellPos destination = task.getDestination();
        if(isPerformed)
        {
            this->MoveObject(destination);
        }
    }

    virtual bool starve()
    {
        return timeSinceEat>=10;
    }
     virtual char getSymbol() const
     {
        return 'D';
    }
};
class Queen:public Ant
{
    private:
        int timeElapsed=0;
        bool hasBred = false;
        int timeSinceBreed=0;
    public:
        Queen()
        {
            this->SetChar('Q');
        }
        Queen(int x, int y)
        {
            cellPos* np = new cellPos(x,y);
            this->MoveObject(*np);
            this->SetChar('Q');
        }
    
    virtual Task getTask(std::vector<Organism> neighbors);
    virtual void performTask(Task task,bool isPerformed)
    {
        if(this->hasBred)
        {
            this->MoveObject(task.getDestination());
        }
    }
     virtual char getSymbol() const
     {
        return 'Q';
    }
    
};

// class for female which is an ant
// female is a worker (w)
class Female:public Ant
{
    public:
    Female()
    {
        this->SetChar('w');
    }
    virtual Task getTask(std::vector<Organism> neighbors)
    {
        
        cellPos newDest = *(new cellPos(this->getPosition().get_x()+(rand()%2)-1,this->getPosition().get_y()+(rand()%2)-1));
        Task* t = new Move(this->getPosition(),newDest);
        return *t;
    }
    virtual void performTask(Task task,bool isPerformed){}
     virtual char getSymbol() const
     {
        return 'w';
    }
};


// class for male which is an ant
// male is o
class Male:public Ant
{
    public:
    Male()
    {
        this->SetChar('o');
    }
    virtual Task getTask(std::vector<Organism> neighbors)
    {
        cellPos newDest = *(new cellPos(this->getPosition().get_x()+(rand()%2)-1,this->getPosition().get_y()+(rand()%2)-1));
        Task* t = new Move(this->getPosition(),newDest);
        return *t;
    }
    virtual void performTask(Task task,bool isPerformed)
    {
        cellPos origin = task.getOrigin();
        cellPos destination = task.getDestination();
        if(isPerformed){
            this->MoveObject(destination);
        }
    }
    virtual bool canMate()
    {
        return true;
    }
     virtual char getSymbol()const
     {
        return 'o';
    }
};

Ant Ant::spawn()
{
    srand(time(NULL));
    int sel = rand()%2;
    if(sel)
    {
        return *(new Male());
    }
    return *(new Female());
};

// create game class to call other classes
class Game
{
    private:
        std::vector<Organism*> organisms;
        Grid grid;

    public:
        Game(){};
        Game(std::vector<Organism*> organisms,Grid g){
            this->organisms = organisms;
            this->grid = g;
        };

        std::vector<Organism*> getOrganisms(){
            return this->organisms;
        }
         Grid getGrid() const{
            return this->grid;
        }

        Organism* getOrganism(int i){
            return this->organisms[i];
        }
        int getOrganismAt(cellPos pos,int& index){
            int count = 0;
            for(int i = 0;i<this->organisms.size();i++){
                if(this->organisms[i]->getPosition()==pos){
                    count+=1;
                    index = i;
                    return 1;
                }
            }
            return count;
        }
       
        int getOrganismAt(cellPos pos,Organism &org){
            int count = 0;
            for(int i = 0;i<this->organisms.size();i++){
                if(this->organisms[i]->getPosition()==pos){
                    count+=1;
                    org = *organisms[i];
                }
            }
            return count;
        }
        int getOrganismCount(){
            return this->organisms.size();
        }

        void removeOrganism(int i){
            this->organisms.erase(this->organisms.begin()+i);
        }
        void addOrganism(Organism *o){
            this->organisms.push_back(o);
        }

        //one step for an organism 
        void stepOrganism(int i);

}; 

