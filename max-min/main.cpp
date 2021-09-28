/*
    Gra min-max.
 
    Zasady:
            n - graczy podaje swoje liczby w przedziale <-100 , 100>
            Wybiramy pojedyńczo, dwójkami lub dodając gracza liczbę maksymalną, na zmianę z minimalną do czasu, aż zostanie jedna wygrana.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void zwloka(int sekund)
{
    time_t   poczatkowy_czas   = time(nullptr);
    while(time(nullptr) - poczatkowy_czas  <  sekund)
    { }                                               
}

int main(){
    int g,l,i,w;
    bool max_min = true, czy_dodac = false;
    cout << "Podaj liczbę graczy: ";
    cin >> g;
    vector<int> v;
    
    for(i = 1;i <= g;i++)
    {
        cout << "Gracz " << i << " podaje swoja liczbe: ";
        cin >> l;
        v.push_back(l);
    }
    
    cout << "Czy lista graczy jest zamknieta? Wczysnij ' t ' jezeli tak, w przeciwnym razie podaj inny znak. ";
    char c;
    cin >> c;
    if(c == 't')
        czy_dodac = true;
    
    while(g)
    {
        w = 0;
        i = 0;
        vector<int> v_z; // vector zastępczy
        while(i < g)
        {
            w++;
            int n = 0;
            if(!czy_dodac){
                cout << "Czy chcesz dodac w tej rundzie graczy? Podaj ich liczbe, jezeli nie chcesz wcisnij 0.\n";
                cin >> n;
            }
            
            if(n != 0)
            {
                vector<int> V;
                V.push_back(v[i]);
                if(i + 1 != g)
                    V.push_back(v[i + 1]);
                
                for(int k = 0;k < n;k++){
                    cout << "Dodatkowy gracz " << i << " podaje swoja liczbe\n";
                    cin >> l;
                    V.push_back(l);
                }
                if(max_min == true)
                    l = *max_element(V.begin(), V.end());
                else
                    l = *min_element(V.begin(), V.end());
                v_z.push_back(l);
            }
            else{
                if(i + 1 == g){
                    cout << "Nie porownujemy liczby " << v[i] << " bo nie ma z czym.\n";
                    v_z.push_back(v[i]);}
                else
                {
                    cout << "Bierzemy pod uwage liczy " << v[i] << " i " << v[i + 1] << endl;
                    if(max_min == true)
                        l = max(v[i], v[i + 1]);
                    else
                        l = min(v[i], v[i + 1]);
                    v_z.push_back(l);
//                cout << "wybrane " << l << endl;
            }}
            cout << "Wygrywa " << v_z.back() << endl << endl;
            zwloka(1);
            i+= 2;
        }
        v.clear();
        
        
        for(l = 0;l < v_z.size();l++)
            v.push_back(v_z[l]);
        
        if(w == 1)
            break;

        cout << "Do kolejnej rundy przechodza liczby: " << endl;
        
         for(l = 0;l < v.size();l++)
            cout << v[l] << " ";

        cout << endl ;
        
        zwloka(2);
       
        max_min = max_min?false:true;
        
        
        g = l;
        
        
        
    }
    
    return 0;
}
