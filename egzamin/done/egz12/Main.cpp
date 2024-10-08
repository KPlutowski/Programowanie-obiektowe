#include <iostream>
#include <array>
#include <memory>
#include <string>


void my_print_el(std::string str)
{
  std::cout<<str;
}

void my_print(std::array<std::unique_ptr<int>, 2>& arr,std::string mid=";",std::string end=" -> ")
{ 
  std::cout<< *(arr[0])<<mid<<*(arr[1])<<end;
}
void my_swap(std::unique_ptr<int>& a,std::unique_ptr<int>&b){
  std::swap(a,b);
}

void my_swap(int& a,int& b){
  std::swap(a,b);
}
int main()
{
  std::array<std::unique_ptr<int>, 2> a = {
      std::unique_ptr<int>(new int{1}),
      std::unique_ptr<int>(new int{2})};

  my_print_el("----------------\n");
  my_print(a, ";", " -> ");
  my_swap(a[0], a[1]);
  my_print(a, ";", " -> ");
  my_swap(*a[0], *a[1]);
  my_print(a);
  my_print_el("\n----------------");
}
//[1;2;] -> [2;1;] -> [1;2;]