#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <memory>
#include <random>
#include <time.h>
#include <algorithm>
using namespace std;

template <typename T>
class CustomSet
{
public:
// Constructors and destructor:
	CustomSet();
	// Default constructor
	
	CustomSet(const CustomSet& other){
        m_size = other.m_size;
        myvec = other.myvec;
    } 
	// Copy constructor. Should construct a copy of "other".
	
	CustomSet(T arr[], int size){
        m_size = size;
		for(int i=0;i<size;i++){
        myvec.push_back(arr[i]);
    	}
	}
    int size(){
        return m_size;
    }
	// Returns the size of the set.
    bool add(const T& item){
        typename vector<T>::iterator it;
        for(it = myvec.begin();it != myvec.end();it++){
            if(item == *it){
                return false;
            }
        }
        myvec.push_back(item);
        m_size++;
        return true;
    }
	// If "item" is already in the set, return false. 
	// Otherwise, add it to the set and return true.
    T* find(const T& item){
        T temp = item;
        T *ptr = &temp ;
        typename vector<T>::iterator it;
        for(it = myvec.begin();it != myvec.end();it++){
            if(item == *it){
                return ptr;
            }
        }
        
        return nullptr;
    }
    bool erase(const T& item){
        if(find(item) == nullptr){
            return false;
        } else {
            typename vector<T>::iterator it;
            for(it = myvec.begin();it != myvec.end();it++){
                if(*it == item ){
                    myvec.erase(it);
                    
                }
            }
        }return true;
    }
	// If "item" is not in the set, return false.
	// Otherwise, erase it from the set and return true.


	CustomSet intersection(const CustomSet& other){
        T arr[]={0};
        CustomSet that = other;
        CustomSet intersection_set(arr,0);
        typename vector<T>::iterator it;
        for(it = that.myvec.begin();it != that.myvec.end();it++){
                if((*this).find(*it) != nullptr){
                    intersection_set.myvec.push_back(*it);
                }
        }
        return intersection_set;
    }
	// This function returns the intersection of two sets (*this and other).
	// In other words, the set of all objects that is in both *this and other.
	// If there is no intersection, just return an empty set.
    void sortSet(){
        sort(myvec.begin(),myvec.end());
    }
	// This function sorts the objects in the set in ascending order.
	// Directly using (std::)sort is enough, if you are using an STL container.
    void printSet(){
        typename vector<T>::iterator it;
        for(it = myvec.begin();it != myvec.end();it++){
            if(it == myvec.begin()){
                cout<<"{";
            }
            cout<<*it;
            if(it >= myvec.begin() && it <= myvec.end()-2){
                cout<<", ";
            }
            if(it == myvec.end()-1){
                cout<<"}\n";
            }
        }
    }
    CustomSet operator+ (const T& item){myvec.push_back(item);m_size++;return (*this);}
	CustomSet operator+ (const CustomSet& that){
    CustomSet temp = that;
    typename vector<T>::iterator it;
        for(it = temp.myvec.begin();it != temp.myvec.end();it++){
            myvec.push_back(*it);
        }
        return (*this);
    }
	CustomSet& operator+= (const T& item){
        T temp = item;
        typename vector<T>::iterator it;
            for(it = myvec.begin();it != myvec.end()+1;it++){
                if(this->find(temp) == nullptr){
                    myvec.push_back(temp);
                }
            }
            return (*this);
    }
	CustomSet& operator+= (const CustomSet& that){
        CustomSet other = that;
        typename vector<T>::iterator it;
            for(it = other.myvec.begin();it != other.myvec.end()+1;it++){
                if(this->find(*it) != nullptr){
                    this->erase(*it);
                }
            }
            (*this) + other;
            return (*this);
    }
	// The operator+ and operator += are overloaded.
	// They can be understood intuitively, or consider this:
	// A set "plus" an item means adding in the item. 
	// A set "plus" a set means taking the union of two sets.
	// However, the difference between + and += is not written here.
	// Try to figure out on your own!

    CustomSet operator- (const T& item){
        typename vector<T>::iterator it;
            for(it = myvec.begin();it != myvec.end()+1;it++){
                if(*it == item ){
                    myvec.erase(it);
                    
                }
            }return (*this);
            }
	CustomSet operator- (const CustomSet& that){
        CustomSet other = that;
        typename vector<T>::iterator it;
            for(it = other.myvec.begin();it != other.myvec.end()+1;it++){
                if(this->find(*it) != nullptr){
                    other.myvec.erase(it);
                }
            }
            return other;
    }
	CustomSet& operator-= (const T& item){
        (*this = *this - item);
        return (*this);
    }
	CustomSet& operator-= (const CustomSet& that){
        CustomSet other = that;
        typename vector<T>::iterator it;
            for(it = other.myvec.begin();it != other.myvec.end()+1;it++){
                if(this->find(*it) != nullptr){
                    this->erase(*it);
                }
            }
            return (*this);
        
    }
	// The operator- and operator -= are overloaded.
	// They can be understood intuitively, or consider this:
	// A set "minus" an item means erasing the item. 
	// A set A "minus" a set B means subtracting B from A, or namely, A\B.
	// However, the difference between - and -= is not written here.
	// Try to figure out on your own!
    CustomSet<std::pair<T, T>> operator* (const CustomSet& that){
        
	}
	// This function returns the Cartesian product of two sets (*this and that).
	// The Cartesian product of two sets is the set of all ordered pairs that satisfy:
	//		The first element of the ordered pair belongs to first set (*this);
	//		The second element of the ordered pair belongs the second set (that).
	// The (std::)pair (in header <utility>) helps representing the object in it.
	// If you have any question with Cartesian products or std::pair, just look up on Internet!
private:
	int m_size;
	vector<T> myvec;
};


int main(){
	int a[5] = { 4,6,32,-4,0 };  
	CustomSet<int> sample1(a, 5);  
	int b[5] = { 4,2,10,-2,0 };  
	CustomSet<int> sample2(b, 5);
    
    //sample1.add(99);
    sample1.sortSet();  
	sample1.printSet(); // prints "{-4, 6, 32}\n" 
    cout<<"Current size is: "<<sample1.size()<<endl;
    
    //cout<<"Find "<<*(sample1.find(99))<<endl;
    
    //sample1.printSet();
    //sample1.intersection(sample2).printSet();
    //(sample1 + 300).printSet();
    //(sample1 + sample2).printSet();
    //(sample1 += 4).printSet();
    //(sample1 += sample2).printSet();

    //(sample1 - 6).printSet();
    //(sample1 - sample2).printSet();
    (sample1 -= sample2).printSet();
    //(sample1 -= 32).printSet();
    
	return 0; 
	}
