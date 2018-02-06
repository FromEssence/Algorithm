/**一维 Binary Indexed Tree
* 2018/2/3
*/
template <typename T, int len>
class BIT{
private:
  T subSum[len];
  int getLowbit(int index){
    return index & (-index);
  }
public:
  BIT(T sum[]){
    memset(subSum, 0, sizeof subSum);
    //make subSum
    for(int i=1; i<=len; i++){
      subSum[i] = sum[i] - sum[i-getLowbit(i)];
    }
  }
  BIT(){ //原始数组初始为空时
    memset(subSum, 0, sizeof subSum);
  }
  T getPreSum(int index){
    T res = 0;
    while(index){
      res += subSum[index];
      index -= getLowbit(index);
    }
    return res;
  }
  void update(int index, int delta){
    while(index <= len){
      subSum[index] += delta;
      index += getLowbit(index);
    }
  }
  T getValue(int index){
    T ans = subSum[index];
    int lca = index - getLowbit(index);
    index--;
    while(index != lca){
      ans -= subSum[index];
      index -= getLowbit(index);
    }
    return ans;
  }

};
