#include<bits/stdc++.h>
using namespace std;
void read(vector<string>&tweets)
{
	fstream newfile;
	newfile.open("tweets.txt",ios::in);
	if(newfile.is_open())
	{
		string tweet;
		while(getline(newfile,tweet))
		{
		tweets.push_back(tweet);
		}
		newfile.close();
	}
	cout<<"The given input file is:"<<endl<<endl;
	for(int i=0;i<tweets.size();i++)
	{
		cout<<tweets[i]<<endl;
	}
	cout<<endl<<endl;
}
bool cmp(pair<string,int> &a,pair<string,int> &b)
{
	return a.second > b.second;
}
void solution(vector<string>tweets)
{
	// score stores the users as key and their respective scores as value.
	map<string,int> score;
	for(int i=0;i<tweets.size();i++)
	{
		// string 's' contains the tweet.
		string s=tweets[i];
		// user indicates the person who wrote the tweet and l(string) indicates the likes of that tweet.
		string user="",l="";
		int j=0;
		while(s[j]!='\t')
		{
			user=user+s[j];
			j++;
		}
		int f=s.size();
		int k=f-1;
		while(s[k]!='\t')
		{
			k--;
		}
		l=s.substr(k+1,f-k);
		// like(integer) indicates the likes of tweet. 
		int like=stoi(l),y=0;
		score[user]+=like*10;
		for(int x=j+1;x<k;)
		{
			//'@' represents start of mentioned user id.
			if(s[x]=='@')
			{
				string mention="";
				while(s[x]!=' ' && x<k)
				{
					mention=mention+s[x];
					x++;
				}
				score[mention]+=like*5+50;
			}
			else
			{
				x++;
			}
		}
	}
	vector<pair<string,int> > temp;
	for(auto p:score)
	{
		temp.push_back(p);
	}
	sort(temp.begin(),temp.end(),cmp);
	cout<<"-----------------------------------------------"<<endl;
	cout<<"PERSONRANK"<<"\t   "<<"USER"<<"\t\t  "<<"SCORE"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	int i=0;
	for(auto it:temp)
	{
		cout<<"   "<<i+1<<"\t\t"<<it.first<<"\t   "<<it.second<<endl;
		i++;
	}
}
int main()
{
	vector<string>tweets;
	read(tweets);
	solution(tweets);
}
