#include<bits/stdc++.h>
#define  int long long int 
using namespace std;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int inf  = LLONG_MAX;

int diffFinder ( vector < vector < int >> & a , vector < vector < int >> & b){
    int ret = 0 ; 
    for ( int i = 0  ; i < 3 ; i ++ ){
        for ( int j = 0 ; j <  3 ; j ++ ){
            if(  a[i][j] != b[i][j]){
                ret ++ ; 
            }
        }
    }
    return ret ; 
}

bool inside ( int i , int j ){
    if ( i < 0 || j < 0 || i >= 3 || j >= 3 ){
        return false ; 
    }
    return true  ; 
}

pair < int , int > zerofinder ( vector < vector <int >> & a ){
    for ( int i = 0  ; i < 3 ; i ++ ){
        for ( int j = 0 ; j <  3 ; j ++ ){
            if(  a[i][j] == 0 ){
                return { i ,   j };
            }
        }
    }
    return {1,1};
}


int dx[] = { 0 , 0 , 1 , -1 };
int dy [] = {1 ,-1 , 0 , 0 };

set < vector < vector < int >>> visi ; 

vector < vector < int > >st  = { { 3 ,2 ,1}, { 4 , 5 ,6 } , { 8 , 7 , 0 }};
// vector < vector < int > >en  = { { 0 ,2 ,1}, { 3 , 5 ,6 } , { 4 , 8 , 7 }};
vector < vector < int > >en  = { { 1 ,2 ,3}, { 4 , 5 ,6 } , { 7 , 8 , 0 }};

priority_queue < pair < pair < int , int > , vector < vector < int >> >> pq ; 


int32_t main(){
std::ios_base ::sync_with_stdio(false);
std::cin.tie(NULL);
std::cout.tie(NULL);
std::cout << std::fixed << std::setprecision(25);
    pq.push ( {{ -1 * diffFinder ( st , en ) , 0 } , st });
    visi .insert ( st );
    int steps  = 0 ;     
    int jk = 1 ;
    while ( pq.top().second != en  ){
        steps ++ ;         
        pair < pair < int , int > , vector < vector < int >> > tp = pq.top(); pq.pop();
        int level = tp.first .second ; 

        vector < vector < int >> tvec = tp.second ; 

        pair < int , int > zeros  = zerofinder ( tvec );
        for ( int i = 0 ; i < 4 ;  i ++ ){
            int ii = zeros.first + dx[i] ; 
            int jj = zeros.second + dy[i];
            vector < vector < int >> tem = tvec ; 
            if ( inside ( ii ,jj ) == 0 ){
                continue; 
            }
            swap ( tem[zeros.first][zeros.second] , tem[ii][jj]);
            if ( visi.find ( tem ) == visi.end()){                
                visi.insert ( tem );
                int dis = diffFinder ( tem , en );
                pq.push ( {{-1 * (dis + level + 1) , level + 1 } , { tem }});
            }
        }
    }
    cout << steps << " this is the cpmputation time \n";
    cout << pq.top().first.second << " this is the distance from inetial position\n";
return 0;
}