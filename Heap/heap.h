/*
 * implementation of the heap structure
 */


class maxHeap{
    vector<int> heapArray;
    int size;
    int maxSize;
    int maxData; //哨兵

    void PercDown(int p){
        int parent, child;
        int root_val = this->heapArray[p];
        for(parent=p; parent*2<=this->size; parent=child){
            child = parent*2;
            if(child<this->size && this->heapArray[child]<this->heapArray[child+1]){
                child ++;
            }
            if(this->heapArray[parent]>=this->heapArray[child]) break;
            else swap(this->heapArray[parent], this->heapArray[child]);
        }
    }
    void Heapify(){
        // O(n)时间调整初始数组为堆
        for(int p=this->size/2; p>0; p--){
            PercDown(p);
        }
    }
public:
    maxHeap(int maxSize){
        heapArray.resize(maxSize+10); // store from index 1
        this->size = 0;
        this->maxSize = maxSize;
        this->maxData = 1e9+10;
        this->heapArray[0] = maxData;
    }
    maxHeap(vector<int> &init_arr){
        this->heapArray = init_arr;
        this->size = this->heapArray.size()-1; //传入的数组的0号位置不适用
        this->Heapify();
   }
    bool isFull(){
        return this->size >= this->maxSize;
    }
    bool isEmpty(){
        return this->size==0;
    }
    int getSize(){
        return this->size;
    }

    void insertHeap(int item){
        int i;
        if(isFull()){
            cout <<"已满"<<endl;
            return;
        }
        i = ++this->size; //插入位置
        for(; this->heapArray[i/2]<item; i/=2){
            // 与父节点比较,将父节点下移
            this->heapArray[i] = this->heapArray[i/2];
        }
        this->heapArray[i] = item;

    }


    void delTop(){
        //1. 把最后一个节点i暂时放到根
        //2. 节点i下沉
        int lastNode = this->heapArray[this->size--];
       // cout<<"to_up="<<lastNode<<endl;
        int parent, child;
        for(parent=1; parent*2<=this->size; parent=child){
            child = parent*2;
            if(child < this->size && this->heapArray[child]<this->heapArray[child+1]){
                // 如果有右节点并且值较大，则根向右方下沉
                child ++;
            }

            if(lastNode >= this->heapArray[child]) break;
            else
                this->heapArray[parent] = this->heapArray[child];

        }
       // cout <<"finalpos=" << parent<<endl;
        this->heapArray[parent] = lastNode;
        return ;
    }

    int getTop(){
        int top = this->heapArray[1];
        return top;
    }
};
