#include <iostream>
#include <cstring>
using namespace std;
//https://icebound.cc/2017/12/11/poj-set.html
// poj_1611

class DisJoinSet{
    /*
     * 并查集；支持logn的查询与合并操作
     */
    int maxSize;
    int useSize; // 此次并查集大小
    int num_sets; // 集合个数
    int *fa; // 存放数组指针
    int *size_set; // 存放指向集合大小的指针

public:
    DisJoinSet(int maxn){
        this->maxSize=maxn;
        fa = new int[maxSize];
        size_set = new int[maxSize];
        useSize = maxSize;
        num_sets = maxn;
    }
    void init(int n){
        for(int i=0; i<n; ++i) size_set[i]=1;
        this->useSize = n;
        this->num_sets = n;
        for(int i=0; i<n; ++i) fa[i] = i; // 初始化节点均独立
    }
    int find(int x) {
        // 寻找x的祖先
        if (fa[x] == x)  // 如果x是祖先则返回
            return x;
        else
            return find(fa[x]);  // 如果不是则x的爸爸问x的爷爷
    }
    void unionSet(int x, int y) {
        // x 与 y 所在家族合并
        // 启发式 按秩
        x = find(x), y = find(y);
        if(x==y) return;
        if (x == y) return;
        if (size_set[x] > size_set[y])  // 保证小的合到大的里
            swap(x, y);
        fa[x] = y;
        size_set[y] += size_set[x];
        --num_sets;
    }
    int count(){
        /*
         * 不相交集合个数
         */
        return this->num_sets;
    }
    int get_group_size(int x){
        int f = find(x);
        return size_set[f];
    }
    ~DisJoinSet(){
        delete []fa;
    }
};

void test_djset(){
    DisJoinSet dset(30000+10);
    int n, m, num_group;
    int a, b;
    while(cin >>n >>m){
        if(!n) break;
        dset.init(n);
        for(int i=0; i<m; ++i){
            cin >>num_group;
            cin >>a;
            while(num_group>1){
                cin >>b;
                dset.unionSet(a, b);
                --num_group;
            }
        }
        cout <<dset.get_group_size(0)<<'\n';
    }
}