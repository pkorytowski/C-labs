
class IntArrayList{
public:
    IntArrayList();
    IntArrayList(int);
    ~IntArrayList();
    void print();
    int find(int);
    void printFind(int);
    void add(int);
    void add(int *,int);
    void add(int,int);
    void add(int, bool);
    void remove(int);
    void remove(int, int);
    
    private:
        int size;
        int maxSize;
        int *tab;

};
