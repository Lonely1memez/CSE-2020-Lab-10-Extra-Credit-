// lab10.cpp
//Name: Antonio Mora
// Date: 6/18/2024
// Description: This program will create a binary search tree and use it to find the minimum and maximum values in the tree
#include "Set.cpp"
using namespace std;

template <typename C>
void print(const Set<C> & s)
{
  for (typename Set<C> :: iterator itr = s.begin(); itr != s.end(); ++itr)
  cout << *itr << ",";
}

template <typename C>
Set<C> operator+(const Set<C> & s1, const Set<C> & s2)
{
  Set<C> result;

  for(typename Set<C> :: iterator itr = s1.begin(); itr != s1.end(); ++itr)
    result.insert(*itr);

  for(typename Set<C> :: iterator itr = s2.begin(); itr != s2.end(); ++itr)
    result.insert(*itr);

  return result;
}

template <typename C>
Set<C> operator-(const Set<C> & s1, const Set<C> & s2)
{
  Set<C> result;

  for(typename Set<C> :: iterator itr = s1.begin(); itr != s1.end(); ++itr)
    result.insert(*itr);

  for(typename Set<C> :: iterator itr = s2.begin(); itr != s2.end(); ++itr)
    result.remove(*itr);

  return result;
}

template <typename C>
Set<C> operator*(const Set<C> & s1, const Set<C> & s2)
{
  Set<C> result;

  for (typename Set <C> :: iterator itr = s1.begin(); itr != s1.end(); ++itr)
    if (s2.contains(*itr))
      result.insert(*itr);

  return result;
}

int main()
{
  int x = 0;
  Set<int> setA;

  cout << "Create setA: " << endl;
  cin >> x;
  while (x !=0)
    {
      setA.insert(x);
      cin >> x;
    }
  
  cout << "The setA is: ";
  print(setA);
  cout << endl ;

  Set<int> setB;

  cout << "create setB: " << endl;
  cin >> x;
  while (x !=0)
    {
      setB.insert(x);
      cin >> x;
    }

  cout <<"The setTwo is: ";
  print(setB);
  cout << endl ;

  Set<int> theunion = setA + setB;
  cout << "union: " << endl;
  print(theunion);
  cout << endl;

  Set<int> thediff = setA - setB;
  cout << "subtraction: " << endl;
  print(thediff);
  cout << endl;

  Set<int> theinter = setA * setB;
  cout << "intersection" << endl;
  print(theinter);
  cout << endl;

  return 0;
}