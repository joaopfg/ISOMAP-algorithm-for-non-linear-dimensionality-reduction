#include <bits/stdc++.h>

#define rep(i,begin,end) for(int i=begin;i<=end;i++)
#define repi(i,end,begin) for(int i=end;i>=begin;i--)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

#define MAXN 33334

typedef pair<int,int> ii;
typedef pair<double,int> di;
typedef pair<int,double> id;

struct point{
	double x,y,z;
};

const double INF = 1000000000.0;
int pointsSz;
vector<point> points;
int par[MAXN], weight[MAXN];


double dist(point p1, point p2){
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y- p2.y)*(p1.y - p2.y) + (p1.z - p2.z)*(p1.z - p2.z));
}

bool comp(ii edge1, ii edge2){
	return dist(points[edge1.first],points[edge1.second]) < dist(points[edge2.first],points[edge2.second]);
}

int Find(int x){
	if(x == par[x]) return x;
	return par[x] = Find(par[x]); 
}

void Union(int u, int v){
	u = Find(u);
	v = Find(v);

	if(u == v) return;

	if(weight[u] < weight[v]) par[u] = v;
	else if(weight[v] < weight[u]) par[v] = u;
	else{
		par[u] = v;
		weight[v]++;
	}
}

bool Connected(vector<ii> (&edges)){
	sort(edges.begin(),edges.end(),comp);

	int sz = (int)edges.size();

	rep(i,0,sz-1){
		if(Find(edges[i].first) != Find(edges[i].second)) Union(edges[i].first,edges[i].second);
	}

	int ref = Find(0);

	rep(i,1,pointsSz-1){
		if(Find(i) != ref) return false; 
	}

	return true;
}

int main(){
fio

double x, y, z;

rep(i,0,1999){
	cin >> x >> y >> z;
	point aux;
	aux.x = x;
	aux.y = y;
	aux.z = z;
	points.push_back(aux);
	par[i] = i;
	weight[i] = 0;
}

pointsSz = (int)points.size();

vector<ii> edges;

rep(i,0,pointsSz-1){
	rep(j,i+1,pointsSz-1){
		if(dist(points[i],points[j]) <= 2.45){
			edges.push_back({i,j});
		}
	}
}

cout << (int)edges.size() << endl;
if(Connected(edges)) cout << "yes" << endl;
else cout << "no" << endl;
return 0;
}