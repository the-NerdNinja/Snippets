
template <class T, class L> struct segment_tree{
  int ss;
  vector<T> tree; T treeidn;
  vector<L> lazy; L lazyidn;

  segment_tree(int n, T tid, L lid):
    ss(n), tree(4*n, tid), lazy(4*n, lid),
    treeidn(tid), lazyidn(lid) {}

  T merge(const T &a, const T &b){

  }

  void lazyapply(T &to, int l, int r, const L &fr){

  }

  void lazymerge(L &to, const L &fr){

  }

  void build(int id, int l, int r, const vector<T> &v){
    if(l==r){
      tree[id]=v[l];
      lazy[id]=lazyidn;
      return;
    }
    int m=l+(r-l)/2;
    build(id*2+1, l, m, v);
    build(id*2+2, m+1, r, v);
    tree[id] = merge(tree[id*2+1], tree[id*2+2]);
    lazy[id] = lazyidn;
  }
  void push(int id, int l, int r){
    if(l!=r) {
      int m=l+(r-l)/2;

      lazyapply(tree[2*id+1], l, m, lazy[id]);
      lazymerge(lazy[2*id+1], lazy[id]);

      lazyapply(tree[2*id+2], m+1, r, lazy[id]);
      lazymerge(lazy[2*id+2], lazy[id]);

      lazy[id] = lazyidn;
    }
  }
  T query(int id, int l, int r, int ql, int qr){
    push(id, l, r);
    if(ql<=l and r<=qr) return tree[id];
    if(ql>r or qr<l) return treeidn;

    int m=l+(r-l)/2;
    T tl = query(id*2+1, l, m, ql, qr);
    T tr = query(id*2+2, m+1, r, ql, qr);
    return merge(tl, tr);
  }
  void update(int id, int l, int r, int ul, int ur, const L &uv) {
    push(id, l, r);
    if (ul<=l and r<=ur) {
      lazyapply(tree[id], l, r, uv);
      lazymerge(lazy[id], uv);
      return;
    }
    if(ul>r or ur<l) return;

    int m=l+(r-l)/2;
    update(id*2+1, l, m, ul, ur, uv);
    update(id*2+2, m+1, r, ul, ur, uv);
    tree[id] = merge(tree[id*2+1], tree[id*2+2]);
  }

  void build(const vector<T> &v){
    build(0, 0, ss-1, v);
  }
  T query(int ql, int qr){
    return query(0, 0, ss-1, ql, qr);
  }
  void update(int ul, int ur, const L &uv){
    update(0, 0, ss-1, ul, ur, uv);
  }
  unsigned long int size(){return ss;}
};
