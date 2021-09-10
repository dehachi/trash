template <class T>
map<T,int> counter(vector<T>& V) {
    map<T,int> cnt;
    for (T i: V) cnt[i] += 1;
    return cnt;
}
