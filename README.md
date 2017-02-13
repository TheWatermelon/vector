# vector
This is a library for vector\<TYPE\> in C++

# Constructors
vector();

vector(size_t);

vector(vector&);

# Methods
size_t size();

void resize(size_t);

bool empty();

void clear();

void swap(vector&);

TYPE& back();

TYPE& front();

void push_back(TYPE&);

void pop_back();

vector& operator=(vector&);

TYPE& operator\[\](size_t);

TYPE& at(size_t);

iterator begin();

iterator end();

reverse_iterator rbegin();

reverse_iterator rend();
