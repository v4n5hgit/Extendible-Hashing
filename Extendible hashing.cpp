#include<bits/stdc++.h>
using namespace std;

struct Bucket
{
    int order=0;
	int ld=0;
	vector<int> v;
};

int gd,cap,oc=0;
map<int,Bucket *> mp;

class Hash{
    public:
    Hash(int gd){
        {
            for(int i=0; i<(1<<gd); i++){
                Bucket * nb = new Bucket;
                nb->ld=gd;
                nb->order=oc++;
                mp[i]=nb;
            }
        }
            cout << "a extendible HASH MAP with global depth "<< gd << " is created." << endl;
    }

    void insert(int val){
            int tr=val%(1<<gd);
            
            if(mp[tr]->v.size()<cap){
                mp[tr]->v.push_back(val);
            }
            else{
                //cout<<val<<" ";
                extend(tr);
                insert(val);
            }
    }
    bool search(int val){
        int tr=val%(1<<gd);
        if(mp[tr]->v.end()==find(mp[tr]->v.begin(), mp[tr]->v.end(), val)) return false;
        else return true;
    }
    void extend(int tr){
        Bucket * nb = new Bucket;
        nb->order=oc++;
        vector<int> temp;
        temp=mp[tr]->v;
        mp[tr]->v.clear();
        if(mp[tr]->ld==gd){
            gd++;
            //cout<<tr<<" "<<gd<<" ";
            mp[tr]->ld=gd;
            nb->ld=gd;
            mp[tr^(1<<(gd-1))]=nb;

            for(int i=0; i<(1<<(gd-1)); i++){
                if(i!=tr){
                    mp[i^(1<<(gd-1))]=mp[i];
                }
            }
            for(int i=0; i<temp.size(); i++)
            {
                int ad=temp[i]%(1<<gd);
                mp[ad]->v.push_back(temp[i]);
            }
        }
        else{
            mp[tr]->ld++;
            mp[tr^(1<<(mp[tr]->ld-1))]=nb;
            nb->ld=mp[tr]->ld;

            for(int i=0; i<temp.size(); i++){
                int ad=temp[i]%(1<<(nb->ld));
                mp[ad]->v.push_back(temp[i]);
            }
        }
    }

    void Delete(int val){
        int tr=val%(1<<gd);
        mp[tr]->v.erase(find(mp[tr]->v.begin(), mp[tr]->v.end(), val));
    }

    void display(){
        {
        cout << gd <<endl;
        cout<< oc <<endl;
        for(int i=0; i<oc; i++){
            for (auto itr = mp.begin(); itr != mp.end(); ++itr) if(itr->second->order==i){
                cout<<itr->second->v.size()<<" "<<itr->second->ld<<endl;
                break;
            }
        }
    }
    }
};

int main(){

    int in,val;
    cin>>gd>>cap;
    Hash ab(gd);
    //ab.intial(gd);

    while(cin>>in){
        //cout<<"2: Insert new value '/n' 3: Search a value '/n' 4: Delete a value '/n' 5: Display status of the hash table '/n' 6: Quit";
        if(in==2){
            cin >> val;
            ab.insert(val);
        }

        else if(in==3){
            cin >> val;
            if(ab.search(val)) cout<< "value '"<<val<< "' is present."<<endl;
            else cout<< "element not found"<<endl;
        }

        else if(in==4){
            cin>>val;
            if(ab.search(val)) ab.Delete(val);
            else cout<< "element not found"<<endl;
        }

        else if(in==5){
            ab.display();
        }

        else if(in==6) break;
    }
    return 0;
}