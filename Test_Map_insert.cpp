#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second > b.second;
}

bool fcmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
}



int main(int argc, char const *argv[])
{

    vector<int> answer;
    vector<int> :: iterator ansi;

	vector<string> genres = {"classic","pop","classic","classic","pop"};
	vector<int> plays = {500,600,150,800,2500};

	map<string, int> total_play;
	multimap<string, vector<int>> each_play;



	map<string, int> :: iterator mi;
	multimap<string, vector<int>> :: iterator mvi;

	for (int i = 0; i < genres.size(); ++i)
	{
		total_play[genres[i]] += plays[i];
		each_play.insert(pair<string, vector<int>>(genres[i],{plays[i],i}));
	}

	vector<pair<string,int>> sorted_total_play(total_play.begin(),total_play.end());
	vector<pair<string,int>> :: iterator si;

	sort(sorted_total_play.begin(),sorted_total_play.end(),cmp);
	
	for(si = sorted_total_play.begin(); si != sorted_total_play.end(); si++){
		vector<pair<int,int>> sorted_each_play;
		vector<pair<int,int>> :: iterator sepi;

		for(mvi = each_play.lower_bound(si->first); mvi != each_play.upper_bound(si->first); mvi++){
			sorted_each_play.push_back(make_pair((mvi->second)[0],(mvi->second)[1]));
		}
		sort(sorted_each_play.begin(),sorted_each_play.end(),fcmp);
		for(sepi = sorted_each_play.begin(); sepi != sorted_each_play.end(); sepi++){
			answer.push_back(sepi->second);
		}

	}
	// for(mvi = each_play.begin(); mvi != each_play.end(); mvi++){

	// 	cout << mvi->first << " : ";

	// 	for (int j = 0; j < 2; ++j)
	// 	{
	// 		cout << (mvi->second)[j] << "  ";
	// 	}

	// 	cout << endl;
	// }
	for ( ansi = answer.begin(); ansi != answer.end(); ansi++){
		cout << *ansi << endl;
	}


	/* code */
	return 0;
}