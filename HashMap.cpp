#ifndef _LIB_HASH_MAP
#define _LIB_HASH_MAP
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  

namespace lib {
  using namespace __gnu_pbds;
  using namespace std;

  /* 1. Maybe remove lazy delete and transfer delete work all to the erase function
   *    PRO: about 400ms faster for N = 5kk in lookup functions (erases will be rare in CP)
   *    CONS: it will increase (almost double) memory usage per node to keep offsets and stuff
   **/

  template<typename Key, typename Value, typename Hash = std::hash<Key>>
  struct GoldenMap {
    enum class State {
      FREE,
      ERASED,
      USED
    };

    enum class Action {
      NONE,
      CREATED,
      REUSED
    };

    struct Node {
      Key key;
      Value value;
      State state = State::FREE;
    };

    const static int shift_amount = 5;

    Node * no;
    size_t size, cap, occ;
    Hash h;

    GoldenMap(size_t capacity) : cap(capacity), size(0){
      assert(capacity > 0 && ((capacity)&(capacity-1)) == 0);
      no = new Node[cap]();
    }

    GoldenMap() : GoldenMap(2){}
    ~GoldenMap() { delete[] no; }

    size_t index(const Key & key, size_t sz_minus_one) const {
      size_t hash = h(key);
      hash ^= hash >> shift_amount;
      return ((11400714819323198485llu * hash) >> shift_amount) & sz_minus_one;
    }

    size_t count(const Key & key) const {
      size_t pos = index(key, cap-1);
      size_t last = cap;

      for(size_t it = 0; it < cap; it++){
        if(no[pos].state == State::FREE)
          return false;
        if(no[pos].state == State::USED && no[pos].key == key){
          if(last != cap)
            swap(no[last], no[pos]);
          return true;
        }
        if(no[pos].state == State::ERASED && last == cap)
          last = pos;

        pos = step_forward(pos, it);
        if(pos >= cap)
          pos %= cap;
      }

      return false;
    }

    Value & operator[](const Key & key) {
      if((occ<<1) > cap)
        rehash(cap << 1);

      size_t pos;
      Action has = add(key, pos, no, cap);
      if(has != Action::NONE){
        size++;
        if(has == Action::CREATED) occ++;
      }

      return no[pos].value;
    }

    void clear() {
      occ = size = 0;
      delete[] no;
      no = new Node[cap = 4]();
    }

    void apply(const function<void(const Key&, Value&)>& func) {
      for(size_t i = 0; i < cap; i++) {
        if(no[i].state == State::USED)
          func(no[i].key, no[i].value);
      }
    }

    void rehash(int n_cap) {
      size_t n_occ = 0;
      Node * n_no = new Node[n_cap]();

      for(size_t i = 0; i < cap; i++){
        if(no[i].state == State::USED){
          size_t pos;
          add(no[i].key, pos, n_no, n_cap);
          n_no[pos].value = no[i].value;
          n_occ++;
        }
      }

      delete[] no;
      no = n_no;
      cap = n_cap;
      occ = n_occ;
    }

    bool erase(const Key & key) {
      size_t pos = index(key, cap-1);;
      for(size_t it = 0; it < cap; it++){
        if(no[pos].state == State::FREE)
          return false;
        if(no[pos].state == State::USED && no[pos].key == key){
          no[pos].state = State::ERASED;
          size--;
          return true;
        }

        pos = step_forward(pos, it);
        if(pos >= cap)
          pos %= cap;
      }

      return false;
    }

    private:

    inline int step_forward(int x, int i) const {
      return x+1;
    }

    Action add(const Key & key, size_t & pos, Node * no, size_t cap) {
      pos = index(key, cap-1);
      size_t last = cap;

      for(size_t it = 0; it < cap; it++){
        if(no[pos].state == State::FREE){
          if(last != cap)
            pos = last;
          no[pos].key = key;
          no[pos].state = State::USED;
          return pos == last ? Action::REUSED : Action::CREATED;
        }

        if(no[pos].state == State::ERASED && last == cap)
          last = pos;
        else if(no[pos].key == key){
          if(last != cap){
            swap(no[pos], no[last]);
            pos = last;
          }
          return Action::NONE;
        }

        pos = step_forward(pos, it);
        if(pos >= cap)
          pos %= cap;
      }

      throw std::logic_error("shouldnt get here in add()");
    }
  };

  template<typename T, typename Hash = hash<T>, typename N = T>
  using GpHashMap = gp_hash_table<
    T, N, Hash, equal_to<T>, direct_mask_range_hashing<T>, linear_probe_fn<>,
    hash_standard_resize_policy<hash_exponential_size_policy<>,
    hash_load_check_resize_trigger<true>, true>>;

  template<typename T, typename Hash = hash<T>>
  using GpHashSet = GpHashMap<T, Hash, null_type>;
}  // namespace lib

#endif
