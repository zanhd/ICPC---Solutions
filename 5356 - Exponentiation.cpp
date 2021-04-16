#include<bits/stdc++.h>
#define FastIO  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define FreOpen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define bigint int64_t
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e18
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define vect vector<int>
#define pair_int pair<int,int>
#define paircout(x) cout<<"{"<<(x).first<<" "<<(x).second<<"}";
#define maxheap(T) priority_queue<T>
#define minheap(T) priority_queue<T,vector<T>,greater<T>>
#define mapofvector map<int,vector<int>>
#define mapofset map<int,set<int>>
#define Matrix(type) vector<vector<type>>
#define loop(i,a,b) for(ll i = a; i <= b; i++)
#define rloop(i,a,b) for(ll i = a; i >= b; i--)
#define loopSTL(itr,STL) for (auto itr = STL.begin(); itr != STL.end(); ++itr)
#define sq(a) (a)*(a)
#define NextPermutationSTL(STL) next_permutation(STL.begin(), STL.end())
#define NextPermutation(a,size) next_permutation(a,a+size)
//string tranform
#define lower(str) transform(str.begin(),str.end(),str.begin(),::tolower);
#define upper(str) transform(str.begin(),str.end(),str.begin(),::toupper);
#define lexcompare(str1,size1,str2,size2) lexicographical_compare(str1, str1+size1, str2, str2+size2)
//Modular Arthematics
#define MOD (ll) 1e9 + 7
#define MOD2 (ll) 1e9 + 9
#define ModAdd(a,b,N) 		((a)%(N) + (b)%(N))%(N);
#define ModSub(a,b,N) 		((a)%(N) - (b)%(N))%(N);
#define ModMultiply(a,b,N)	((a)%(N) * (b)%(N))%(N);
//extra
#define ceil_div(a,b) (a+b-1)/(b);
#define gcd(a,b) __gcd((long long int) a,(long long int) b)
using namespace std;

string stringMultiply(string num1, string num2)
{
	int len1 = num1.size();
	int len2 = num2.size();

	if (len1 == 0 || len2 == 0) return "0";

	vector<int> result(len1 + len2, 0);

	int i_n1 = 0;
	int i_n2 = 0;

	for (int i = len1 - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - '0';
		i_n2 = 0;

		for (int j = len2 - 1; j >= 0; j--)
		{
			int n2 = num2[j] - '0';
			int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
			carry = sum / 10;
			result[i_n1 + i_n2] = sum % 10;
			i_n2++;
		}

		if (carry > 0) result[i_n1 + i_n2] += carry;
		i_n1++;
	}

	int i = result.size() - 1; while (i >= 0 && result[i] == 0) i--;

	if (i == -1) return "0";

	string s = ""; while (i >= 0) s += std::to_string(result[i--]);
	return s;
}

string power(string str, ll n)
{
	string ans = "1";
	while (n--) ans = stringMultiply(ans, str);
	return ans;
}

string removeDecimal(string str)
{
	string ans = "";
	for (auto x : str)
	{
		if (x == '.') continue;
		ans += x;
	}

	return ans;
}

string removeLeadingZeros(string str)
{
	bool found = 0;
	string ans = "";
	for (auto x : str)
	{
		if (!found && x == '0') continue;
		found = 1;
		ans += x;
	}
	return ans;
}

string removeTrailingZeros(string str)
{
	bool found = 0;
	string ans = "";
	rloop(i, str.length() - 1, 0)
	{
		if (!found && str[i] == '0') continue;
		found = 1;
		ans = str[i] + ans;
	}
	return ans;
}

void Solve()
{
	string x;
	ll n;
	while (cin >> x >> n)
	{
		ll decimal = -1;
		loop(i, 0, x.length() - 1)
		{
			if (x[i] != '.') continue;
			decimal = i;
			break;
		}

		if (decimal == -1) cout << power(x, n);
		else
		{
			x = removeDecimal(x);
			string ans = power(x, n);

			decimal = n * (x.length() - decimal);

			while (ans.length() <= decimal) ans = "0" + ans;

			ll pos = ans.length() - 1 - decimal;

			ans = ans.substr(0, pos + 1) + "." + ans.substr(pos + 1);

			ans = removeLeadingZeros(ans);
			ans = removeTrailingZeros(ans);

			if (ans[ans.size() - 1] == '.') ans += '0';

			cout << ans;

		}

		cout << endl;

	}

}

int main(int argc, char const *argv[])
{

	FastIO;
	//FreOpen;
	int T = 1;
	//cin >> T;
	while (T--) Solve();
	return 0;
}