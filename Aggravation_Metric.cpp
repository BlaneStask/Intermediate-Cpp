// Description - This progam outputs an integer representing the Index of
// Indentifiable Inversions of the configuration.

#include <iostream>
#include <string>
using namespace std;

class person{
        private:
            int feet_h;
            int inch_h;
            string name;
        public:
            person(string nam, int feet, int inch){
                name = nam;
                feet_h = feet;
                inch_h = inch;
            };
            int accessor(string name);
    
            friend bool operator == (const person& hf, const person& hi);
            friend bool operator < (const person& hf, const person& hi);
            friend bool operator > (const person& hf, const person& hi);
            friend bool operator <= (const person& hf, const person& hi);
            friend bool operator >= (const person& hf, const person& hi);
};

int main ()
{
    int count = 0;
    int n;
    //number of people
    cin >> n;
    //creates dynamic person array
    person** list = new person*[n];
    //calls vals to cin values
    for(int i = 0; i < n; i++){
        string name;
        int feet_h, inch_h;
        cin >> name >> feet_h >> inch_h;
        list[i] = new person(name, feet_h, inch_h);
    }//O(n)
    int i = 0;
    if(n > 0 && n <= 10000){
        while(i < n - 1){
            for(int j = i + 1; j < n; j++){
                //larger but not last spot comparison
                if (*list[i] > *list[j] && j != n - 1){
                    count++;
                }
                //last spot comparison
                else if(*list[i] > *list[j] && j == n - 1){
                    count++;
                    j = i + 1;
                    i++;
                }
                //next first comparison slot
                else{
                    j = i + 1;
                    i++;
                }
            }
        }
    }//O(n^2)
    cout << count;
    //deletes dynamic array, and sets to NULL
    delete [] list;
    list = NULL;
    return 0;
}

//overloading operators, converting feet to inches

bool operator == (const person& hf, const person& hi){
    return (hf.feet_h == hi.feet_h) && (hf.inch_h == hi.inch_h);
}

bool operator < (const person& hf, const person& hi){
    return (hf.feet_h * 12 + hf.inch_h < hi.feet_h * 12 + hi.inch_h);
}

bool operator > (const person& hf, const person& hi){
    return (hf.feet_h * 12 + hf.inch_h > hi.feet_h * 12 + hi.inch_h);
}

bool operator <= (const person& hf, const person& hi){
    return (hf.feet_h * 12 + hf.inch_h <= hi.feet_h * 12 + hi.inch_h);
}

bool operator >= (const person& hf, const person& hi){
    return (hf.feet_h * 12 + hf.inch_h >= hi.feet_h * 12 + hi.inch_h);
}
