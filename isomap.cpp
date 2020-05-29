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
vector<id> g[MAXN];
map<ii,double> d;
map<ii,double> dEdges;

double dist(point p1, point p2){
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y- p2.y)*(p1.y - p2.y) + (p1.z - p2.z)*(p1.z - p2.z));
}

void Dijkstra(int s){
	rep(i,0,pointsSz-1) d[{s,i}] = INF;

	d[{s,s}] = 0.0;
	dEdges[{s,s}] = 0.0;

	set<di> q;
	q.insert({d[{s,s}],s});

	int cur, to;
	double weight;

	while(!q.empty()){
		cur = q.begin()->second;
		q.erase(q.begin());

		rep(i,0,(int)g[cur].size() - 1){
			to = g[cur][i].first;
			weight = g[cur][i].second;

			if(d[{s,cur}] + weight < d[{s,to}]){
				q.erase({d[{s,to}],to});
				d[{s,to}] = d[{s,cur}] + weight;
				dEdges[{s,to}] = dEdges[{s,cur}] + 1.0;
				q.insert({d[{s,to}],to});
			}
		}
	}
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
}

pointsSz = (int)points.size();

rep(i,0,pointsSz-1){
	rep(j,i+1,pointsSz-1){
		if(dist(points[i],points[j]) <= 5.0){
			g[i].push_back({j,dist(points[i],points[j])});
			g[j].push_back({i,dist(points[i],points[j])});
		}
	}
}

rep(i,0,pointsSz-1) Dijkstra(i);

rep(i,0,pointsSz-1){
	rep(j,0,pointsSz-1) printf("%lf ",dEdges[{i,j}]*dEdges[{i,j}]);
	printf("\n");
}
return 0;
}