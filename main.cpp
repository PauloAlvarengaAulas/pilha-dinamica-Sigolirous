#include <stack> 
#include <iostream> 
using namespace std; 
template <class T> class Pilha { 
private: 
    template <class TT> class Celula { 
    public: 
        Celula<TT> *prox; 
        TT valor; 
 
        Celula(TT v) { 
            this->valor = v; 
            prox = nullptr; 
        } 
        }; 
        int tamanho; 
        Celula<T> *topo; 
public: 
        Pilha() { 
            topo = nullptr; 
            tamanho = 0; 
        } 
        ~Pilha() { 
            Celula<T> *clear; 
            while(topo!=nullptr) { 
            clear=topo; 
            topo = topo->prox; 
            delete clear; 
            } 
        } 
        int getTamanho() { 
            return tamanho; 
        } 
        bool inserir(const T &valor) { 
            if(this->topo == nullptr) { 
                this->topo = new Celula<T>(valor); 
            } else { 
                Celula<T> *clear = new Celula<T>(valor); 
                clear->prox = this->topo; 
                this->topo = clear; 
            } 
            ++tamanho; 
            return true; 
        } 
        bool excluir(void) { 
            if(this->topo==nullptr) { 
                return false; 
            } else { 
                Celula<T> *clear; 
                clear = topo; 
                this->topo = this->topo->prox; 
                delete clear; 
                --tamanho; 
                return true;
            } 
        } 
        void mostrar() { 
            if(this->topo== nullptr) { 
                cout << "<<nada>>"; 
            } else { 
                cout << this->topo->valor; 
            } 
            cout << endl; 
        } 
        char getFirst(){
            if(this->topo== nullptr) { 
                return '-'; 
            } else { 
                return this->topo->valor; 
            } 
        }
}; 

int main() { 
    int n, rgt = 0, lft = 0, dim;

    Pilha<char> mine;
    Pilha<char> clear;
    char line[1001];
    cin>>n;
    do{
        cin.getline(line, 1001);
        for(int j = 0; line[j]; j++){
            mine.inserir(line[j]);
        }
        for(int k = mine.getTamanho(); k >= 1; k--){
            if(mine.getFirst()=='>' or mine.getFirst()=='<'){
                clear.inserir(mine.getFirst());
                mine.excluir();
            }else{
                mine.excluir();
            }
        }
        for(int l = clear.getTamanho(); l >= 1; l--){
            if(clear.getFirst()=='<'){
                rgt++;
                clear.excluir();
            }else if(clear.getFirst()=='>'){
                if(rgt > 0){
                    lft ++;
                    rgt--;
                    clear.excluir();
                }
            }
            dim = lft;
        }
        cout<<dim<<endl;
        rgt = lft = 0;
        n--;
    }while(n >= 0);
    return 0;
} 