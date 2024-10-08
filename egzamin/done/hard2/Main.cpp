#include<iostream>
#include<deque>


template<typename T = int, 
template< typename F = T, typename Allocator = std::allocator<F>> class StorageType =  std::deque >
struct fifo
{ 

    // Member typedef to define the storage type
  using storage_type = StorageType<T>;

  fifo(){
    std::cout<<__PRETTY_FUNCTION__<<"\n";
  }

  
  void push(T i){
    _data.push_back(i);
  }

  T get(){
    T tmp = _data[0];
    _data.pop_front();
    return tmp;
  }

  size_t size(){
    std::cout<<"\n";
    return _data.size();
  }

  using value_type = T;

  typename storage_type::const_iterator begin() const { 
    std::cout<<"\n";
    return _data.begin(); }
  typename storage_type::const_iterator end() const { return _data.end(); }


  private:
    storage_type _data;

};




int main(){
    fifo<> ft;
    for(int i: {0,1,2,3,4})
        ft.push(i);

    fifo<int, std::deque> f = ft;

    std::cout << f.get();
    std::cout << f.size();

    for(fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i)
        std::cout << *i << ",";
}
/*
  Wynik:
  fifo<T, StorageType>::fifo() [with T = int, StorageType = std::deque]
  0
  4
  1,2,3,4,
*/