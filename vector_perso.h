#ifndef VECTOR_H

#define VECTOR_H

template <typename TYPE>
class vector {
private:
    /* Attributs */

    /* Tableau des <TYPE> elements */
    TYPE* TAB;
    /**
     * DIM est la taille effective du tableau 
     * CAP est la taille maximale du tableau
     */
    size_t DIM, CAP;

public:
    /* Constructeurs */

    /* Constructeur vide */
    vector(size_t d=0) {
        this.DIM=0;
        this.TAB=new TYPE[0];
    }
    /* Constructeur n */
    vector(size_t d) {
        this.DIM=d;
        this.TAB=new TYPE[d];
    }
    /* Constructeur copie */
    vector(const vector& source):vector(size(source)) {
    	/* swap() */
    }
	
	/* Destructeur */
	
	~vector() {
		delete[] this.TAB;
		this.DIM=0;
		this.CAP=0;
	}
	
    /* Methodes */

    size_t size()const {return this.DIM;}
    void resize(size_t);
    void push_back(TYPE);
    void pop_back();

    /* Operateurs */

    /* Indexation */
    TYPE& operator[](size_t i) {return this.TAB[i];}
    const TYPE& operator[](size_t i)const {return this.TAB[i];}
    /* Affectation */
    TYPE& operator=(const vector<TYPE>&);
};

/* Definition des methodes */

template <typename TYPE>
void vector<TYPE>::resize(size_t nDIM) {
    /* Faut-il agrandir physiquement */
    if(nDIM>this.CAP) {
        this.CAP=std::max(this.DIM,this.CAP+this.CAP);
        TYPE* vTAB=this.TAB;
        this.TAB=new TYPE[this.CAP];

        for(size_t i=0; i<this.DIM; ++i) {this.TAB[i]=vTAB[i];}

        delete[] vTAB;
    }
    /* Faut-il reduire logiquement? */
    for(size_t i=nDIM; i<this.DIM; ++i) {this.TAB[i]=TYPE();}
    /* Mise a jour de la dimension */
    this.DIM=nDIM;

}

template <typename TYPE>
void vector<TYPE>::push_back(TYPE x) {
    this.resize(this.DIM+1);
    this.TAB[this.DIM-1]=x;
}

template <typename TYPE>
void vector<TYPE>::pop_back() {
	resize(size()-1);
}

/* Definition des operateurs */

template <typename TYPE>
TYPE& vector<TYPE>::operator=(const vector<TYPE>& V) {
	if(this.DIM!=V->DIM) {this.resize(V->DIM);}
	/* Affectation du TYPE */
	// for(size_t i=0; i<this.DIM; ++i) {this.TAB[i]=V->TAB[i];}
	return V;
}

#endif /* VECTOR_H */