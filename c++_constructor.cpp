class Empty{};

equals to:

class Empty{
public:
	Empty(){}//constructor
	Empty(const Empty& rhs){}//copy
	~Empty(){}//destructor
	virtual  //????
	Empty& operator=(const Empty&b);   // if we use ...(..){} the inside curly brackets should return something
}

For objects, their default constructor is called. For example, for std::string, the default constructor sets it to an empty string. If the object's class does not have a default constructor, it will be a compile error if you do not explicitly initialize it.

For primitive types (pointers, ints, etc), they are not initialized -- they contain whatever arbitrary junk happened to be at that memory location previously.

For references (e.g. std::string&), it is illegal not to initialize them, and your compiler will complain and refuse to compile such code. References must always be initialized.

int *ptr;  // Contains junk
    string name;  // Empty string
    string *pname;  // Contains junk
    string &rname;  // Compile error
    const string &crname;  // Compile error
    int age;  // Contains junk

;


The concept of the virtual function solves the following problem:

In object-oriented programming, when a derived class inherits from a base class, an object of the derived class may be referred to via a pointer or reference of the base class type instead of the derived class type. If there are base class methods overridden by the derived class, the method actually called by such a reference or pointer can be bound either 'early' (by the compiler), according to the declared type of the pointer or reference, or 'late' (i.e., by the runtime system of the language), according to the actual type of the object referred to.

Virtual functions are resolved 'late'. If the function in question is 'virtual' in the base class, the most-derived class's implementation of the function is called according to the actual type of the object referred to, regardless of the declared type of the pointer or reference. If it is not 'virtual', the method is resolved 'early' and the function called is selected according to the declared type of the pointer or reference.

Virtual functions allow a program to call methods that don't necessarily even exist at the moment the code is compiled.

In C++, virtual methods are declared by prepending the virtual keyword to the function's declaration in the base class. This modifier is inherited by all implementations of that method in derived classes, meaning that they can continue to over-ride each other and be late-bound. And even if methods owned by the base class call the virtual method, they will instead be calling the derived method.


