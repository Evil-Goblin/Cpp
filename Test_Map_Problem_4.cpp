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

vector<int> solution(vector<string> genres, vector<int> plays) {

    vector<int> answer;

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
		int count = 0;
		vector<pair<int,int>> sorted_each_play;
		vector<pair<int,int>> :: iterator sepi;

		for(mvi = each_play.lower_bound(si->first); mvi != each_play.upper_bound(si->first); mvi++){
			sorted_each_play.push_back(make_pair((mvi->second)[0],(mvi->second)[1]));
		}
		sort(sorted_each_play.begin(),sorted_each_play.end(),fcmp);
		for(sepi = sorted_each_play.begin(); sepi != sorted_each_play.end(); sepi++){
			count++;
			answer.push_back(sepi->second);
			if (count == 2)
			{
				break;
			}
		}

	}


    return answer;
}

int main(int argc, char const *argv[])
{
	vector<string> genres = {"classic","pop","classic","classic","pop"};
	vector<int> plays = {500,600,150,800,2500};

	solution(genres,plays);

	/* code */
	return 0;
}