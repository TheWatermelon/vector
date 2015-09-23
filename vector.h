//
//  vector.h
//  Jean Goulet
//  septembre 2015
//  version INCOMPLETE
//  modifie par:
//
//

#ifndef _vector_h
#define _vector_h

#include <iostream>
#include <cassert>

template <typename TYPE>
class vector{
private:
    TYPE *DEBUT,*FINDIM,*FINCAP;
public:
    vector();
    vector(size_t);
    ~vector();
    vector(const vector&);
    vector& operator=(const vector&);
    
    class iterator;
    class reverse_iterator;
    
    void resize(size_t);   
    size_t size()const;
    bool empty()const;
    void clear();
    void swap(vector&);
    
    TYPE& back();
    const TYPE& back()const;
    TYPE& front();
    const TYPE& front()const;
    void push_back(const TYPE&);
    void pop_back();
    TYPE& operator[](size_t);
    const TYPE& operator[](size_t)const;
    TYPE& at(size_t);
    const TYPE& at(size_t)const;
    
    //fonctions d'iteration du vector
    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();

    //code jetable
    void afficher()const;
};

template <typename TYPE>
std::ostream& operator<<(std::ostream&,const vector<TYPE>& V);

////////////////////////////////////////////////////////////////
//class iterator et reverse_iterator

template<typename TYPE>
class vector<TYPE>::iterator{
private:
    TYPE *POINTEUR;
public:
    iterator(TYPE *P=nullptr):POINTEUR(P){}
    TYPE& operator*(){return *POINTEUR;}
    iterator operator++(){return iterator(++POINTEUR);}    //++i
    iterator operator++(int){return iterator(POINTEUR++);} //i++
    iterator operator--(){return iterator(--POINTEUR);}    //--i
    iterator operator--(int){return iterator(POINTEUR--);} //i--
    bool operator==(const iterator& droite){return POINTEUR==droite.POINTEUR;}
    bool operator!=(const iterator& droite){return POINTEUR!=droite.POINTEUR;}
};

template<typename TYPE>
class vector<TYPE>::reverse_iterator{
private:
    //la representation
public:
    //l'interface
};

////////////////////////////////////////////////////////////////
// constructeurs, affectateur et destructeur

template <typename TYPE>
vector<TYPE>::vector():vector(0){}

template <typename TYPE>
vector<TYPE>::vector(size_t D){
    DEBUT=new TYPE[D];
    FINDIM=FINCAP=DEBUT+D;
}

template <typename TYPE>
vector<TYPE>::vector(const vector& source):vector(){
    std::cout<<"constructeur copieur A VENIR"<<std::endl;
}

template <typename TYPE>
vector<TYPE>& vector<TYPE>::operator=(const vector& source){
    if(this!=&source){
        vector copie(source);
        swap(copie);
        }
    return *this;
}

template <typename TYPE>
vector<TYPE>::~vector(){
    clear();
}

////////////////////////////////////////////////////////////////
// selecteurs et mutateurs

template <typename TYPE>
void vector<TYPE>::resize(size_t nouv_dim){
    std::cout<<"version STUB de resize"<<std::endl;
    //fonction temporaire de type STUB
    //qui fait un vector de 10 elements
    //et une capacite de 15
    //il faut remplacer tout ce code
    if(DEBUT!=FINCAP)return;
    size_t RESERVE=5;
    size_t DIM=10;
    size_t CAP=DIM+RESERVE;
    DEBUT=new TYPE[CAP];
    FINDIM=DEBUT+DIM;
    FINCAP=FINDIM+RESERVE;
}

template <typename TYPE>
size_t vector<TYPE>::size()const{
    return FINDIM-DEBUT;
}

template <typename TYPE>
bool vector<TYPE>::empty()const{
    return DEBUT==FINDIM;
}

template <typename TYPE>
void vector<TYPE>::clear(){
    std::cout<<"fonction clear A VENIR"<<std::endl;
}

template <typename TYPE>
void vector<TYPE>::swap(vector<TYPE>& v){
    std::swap(DEBUT,v.DEBUT);
    std::swap(FINDIM,v.FINDIM);
    std::swap(FINCAP,v.FINCAP);
}

template <typename TYPE>
TYPE& vector<TYPE>::back(){
    std::cout<<"fonction back A VENIR"<<std::endl;
}
    
template <typename TYPE>
const TYPE& vector<TYPE>::back()const{
    std::cout<<"fonction back const A VENIR"<<std::endl;
}

template <typename TYPE>
TYPE& vector<TYPE>::front(){
    return *DEBUT;
}

template <typename TYPE>
const TYPE& vector<TYPE>::front()const{
    return *DEBUT;
}

template <typename TYPE>
void vector<TYPE>::push_back(const TYPE& x){
    resize(size()+1);
    back()=x;
}

template <typename TYPE>
void vector<TYPE>::pop_back(){
    resize(size()-1);
}

template <typename TYPE>
TYPE& vector<TYPE>::operator[](size_t i){
    std::cout<<"fonction operator[] A VENIR"<<std::endl;
}

template <typename TYPE>
const TYPE& vector<TYPE>::operator[](size_t i)const{
    std::cout<<"fonction operator[] const A VENIR"<<std::endl;
}

template <typename TYPE>
TYPE& vector<TYPE>::at(size_t i){
    assert(i<size());
    return (*this)[i];
}
template <typename TYPE>
const TYPE& vector<TYPE>::at(size_t i)const{
    assert(i<size());
    return (*this)[i];
}



////////////////////////////////////////////////////////////////
//fonctions d'iteration de la class vector

template <typename TYPE>
typename vector<TYPE>::iterator vector<TYPE>::begin(){
    return vector<TYPE>::iterator(DEBUT);
    }

template <typename TYPE>
typename vector<TYPE>::iterator vector<TYPE>::end(){
    return vector<TYPE>::iterator(FINDIM);
    }

template <typename TYPE>
typename vector<TYPE>::reverse_iterator vector<TYPE>::rbegin(){
    std::cout<<"fonction rbegin A VENIR"<<std::endl;
}

template <typename TYPE>
typename vector<TYPE>::reverse_iterator vector<TYPE>::rend(){
    std::cout<<"fonction rend A VENIR"<<std::endl;
}


////////////////////////////////////////////////////////////////
// code jetable
// Attention! cette fonction d'affichage ne fonctionne qu'avec
// de elements qui possedent l'operateur << des ostreams.

template <typename TYPE>
void vector<TYPE>::afficher()const{
    using namespace std;

	cout<<"Etat du vector a l'adresse: "<<this<<endl;
    size_t i;
	cout<<" DEBUT:  "<<DEBUT<<endl;
	cout<<" FINDIM: "<<FINDIM<<" ("<<(FINDIM-DEBUT)<<")"<<endl;
	cout<<" FINCAP: "<<FINCAP<<" ("<<(FINCAP-DEBUT)<<")"<<endl;
    size_t DIM=FINDIM-DEBUT;
    size_t VIDE=DIM;
    if(VIDE>11)VIDE=DIM-11;else VIDE=0;
    size_t CAP=FINCAP-DEBUT;
	for(i=0;i<DIM;++i)
		if(i<10 || i>VIDE)cout<<" "<<i<<": "<<DEBUT[i]<<endl;
        else {cout<<" ..."<<endl;i=VIDE;}
    
    if(CAP>DIM){
        cout<<" "<<i;
        if(CAP-DIM>1)cout<<" a "<<CAP-1;
        cout<<": (--en reserve--)"<<endl;
    }
}

template <typename TYPE>
std::ostream& operator<<(std::ostream& out,const vector<TYPE>& V){
    char delim='[';
    size_t S=V.size();
    if(S==0)out<<delim;
    if(S>40)S=40;
    for(size_t i=0;i<S;++i){
        out<<delim<<V[i];
        delim=',';
        }
    out<<"]";
    return out;
}



#endif
