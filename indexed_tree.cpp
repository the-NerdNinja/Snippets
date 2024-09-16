
template <class T> struct indexed_tree{
  ll ss;
  vector<T> bit;
 
  indexed_tree(ll n): ss(n), bit(n+1, 0) {}
 
  void update(ll i, ll delta){
    for(++i; i<=ss; i+=i&-i) bit[i]+=delta;
  }
  T query(int i){
    T res=0;
    for(++i; i>0; i-=i&-i) res+=bit[i];
    return res;
  }
  long unsigned int size(){return ss;}
};
