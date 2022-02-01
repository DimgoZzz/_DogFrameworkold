# Class 
``` 
class SomeClass; 			//each new world starts with Caps
class SIMDVector; 			//abbreviation full CAPS
using UInt64 = int64_t;		//

```
#### Class Members 
```
Class SomeClass
{
	///////Constructors First//
	SomeClass();
	~SomeClass();
	///////////////////////////
	
	///////Next Functions//////
public:
	Int getVar();
	void setVar();
	///////////////////////////
	
	///////Last Members////////
	///////Public First////////
public:
	Int publicVar_;			   //class vars starts with low letter, ends with _
private:
	Int privateVar_;
	///////////////////////////
}
```
# Functions 
```
//stars with low letter, then each new word Starts with Caps
void get();
Int setX();
Double someLongFooName();
```
#### Function members 
```
void Foo(Int outsideFuntionVar ) //Same as inside 
{
	Int insideFunctionVar; //starts with low letter, then each new word with Caps
}
```
 # [Other](https://geosoft.no/development/cppstyle.html)