#ifndef network_H
#define network_H

#include <bits/stdc++.h>

using namespace std;

struct Node {
	string columnName;
	vector<Node*> parent;
	vector<Node*> next;
	vector<string> values;
	unordered_set<string> type;
	vector<pair<string,vector<string>>> condition ;
	vector<pair<string,vector<double>>> probability;
};

struct allNode
{
	vector<Node *> arr;
};

class Bayesian_Network{

	public:
	// data input: 				unordered_map<string,vector<string>>
	// input relation data : 	vector<pair<string,string>>


	unordered_map<string,vector<string>> data;
	vector<pair<string,string>> relations;

	Bayesian_Network(unordered_map<string,vector<string>> inputdata,vector<pair<string,string>> inputrelation){
		data=inputdata;
		relations=inputrealtion;
	}

	//check the null values is there oe not;// special


	// create the seperate node and strore all of the in allNode (harshit)
	// put the name, values, type
	void Add_data(){
        for(auto x : data){
            Node *p= new Node(x.first);
            p->values=x.second;
            unordered_set<string> s;
            int n=x.second.size();
            for(int i=0;i<n;i++){
                s.insert(x.second[i]);
            }
            p->type=s;
            model->arr.push_back(p);

        }
    }
	


	//based on given relation find the relation and put in each nodes parent and children (Akash FuckBoy)
	void add_relation(){
        string ancestor, child;

        for(int j=0; j<relations.size(); j++){
            ancestor=relations[j].first, child=relations[j].second;

            for(int i=0; i<model->arr.size(); i++){
                
                if( model->arr[i]->columnName == (child)) {
                    model->arr[i]->parent.push_back(ancestor);
                }

                if( model->arr[i]->columnName == (ancestor) ) {
                    model->arr[i]->next.push_back(child);
                }
            }
        }
    }

	// check the relation { Rajnish }
	bool checkCycle(int node, unordered_map<string, list<string> > &adj, unordered_map<string , bool >& visited , unordered_map<string , bool > & dfsvisited) {
		visited[node] = true;
		dfsvisited[node] = true;

		for(auto neighbour: adj[node]){
			if(visited[neighbour]==false){
				bool cycleDetected = checkCycle(neighnour,adj,visited,dfsvisited);
				if(cycleDetected)
					return true;
			}
			else if(dfsvisited[neighbour]){
				return true
			}
		}
		dfsvisited[node] = false;
		return false;
	}


	// taking no of nodes or vertices 
	bool isDAG(int vertices, vector<pair<string,string>> relation)
	{
		// No. of nodes or vertices
		int vertices;

		// create a adjacency list for all nodes
		unordered_map<string, list<string> > adj;


		for(int i=0;i<relation.size();i++){
			int u = relation[i].first;
			int v = relation[i].second;

			adj[u].push_back(v);
		}

		// make a visited and dfsvisited map 
		unordered_map<string , bool > visited;
		unordered_map<string , bool > dfsvisited;
		
		for(int i = 1; i <=vertices; i++)
		{
			if(visited[i]==false){
				// call checkcycle function for detect DAG in a given relation 
				if(checkCycle(i, adj, visited, dfsvisited)) {
					return true;
				}
			}
		}
		return false;
	}


	//filling the conidtion table based on the parent node;
	vector<vector<int>> build(vector<vector<int>> & arr, int type){
        vector<vector<int>> ar;
        if(arr.size()==0){
            for(int i=0; i<type; i++){
                vector<int> a = {i};
                ar.push_back(a);
            }
        }
        else{
            for(int j=0; j<type; j++){
                for(int i=0; i<arr.size(); i++){
                    vector<int> temp = arr[i];
                    temp.push_back(j);
                    ar[i].push_back(temp);
                }
            }
        }

        return ar;
    }

    vector<pair<string, vector<string>>> solve(vector<Node*> parent, int i, vector<string> &v, int n, Node* A){
		vector<vector<int>> table;
        
        for(int i=0; i<parent.size(); i++){
            int val = parent->type.size();
            v.push_back(parent->columnName);
            build(table, val);
        }
        // if(i==n){
		// 	for(int i=0;i<n;i++){
                
		// 	}
		// }
	}

	// based on condition we havew to create the probabolity;

	//got to all nodes and find the probability and multuiply it;

};


#endif