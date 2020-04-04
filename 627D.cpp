// C++ program to prlong long the number of elements 
// greater than k in a subarray of range L-R. 
#include <bits/stdc++.h> 
using namespace std; 

// Structure which will store both 
// array elements and queries. 
struct node { 
	long long pos; 
	long long l; 
	long long r; 
	long long val; 
}; 

// Boolean comparator that will be used 
// for sorting the structural array. 
bool comp(node a, node b) 
{ 
	// If 2 values are equal the query will 
	// occur first then array element 
	if (a.val == b.val) 
		return a.l > b.l; 

	// Otherwise sorted in descending order. 
	return a.val > b.val; 
} 

// Updates the node of BIT array by adding 
// 1 to it and its ancestors. 
void update(long long* BIT, long long n, long long idx) 
{ 
	while (idx <= n) { 
		BIT[idx]++; 
		idx += idx & (-idx); 
	} 
} 
// Returns the count of numbers of elements 
// present from starting till idx. 
long long query(long long* BIT, long long idx) 
{ 
	long long ans = 0; 
	while (idx) { 
		ans += BIT[idx]; 

		idx -= idx & (-idx); 
	} 
	return ans; 
} 

// Function to solve the queries offline 
void solveQuery(long long arr[], long long n, long long QueryL[], long long QueryR[], long long QueryK[], long long q) 
{ 
	// create node to store the elements 
	// and the queries 
	node a[n + q + 1]; 
	// 1-based indexing. 

	// traverse for all array numbers 
	for (long long i = 1; i <= n; ++i) { 
		a[i].val = arr[i - 1]; 
		a[i].pos = 0; 
		a[i].l = 0; 
		a[i].r = i; 
	} 

	// iterate for all queries 
	for (long long i = n + 1; i <= n + q; ++i) { 
		a[i].pos = i - n; 
		a[i].val = QueryK[i - n - 1]; 
		a[i].l = QueryL[i - n - 1]; 
		a[i].r = QueryR[i - n - 1]; 
	} 

	// In-built sort function used to 
	// sort node array using comp function. 
	sort(a + 1, a + n + q + 1, comp); 

	// Binary Indexed tree with 
	// initially 0 at all places. 
	long long BIT[n + 1]; 

	// initially 0 
	memset(BIT, 0, sizeof(BIT)); 

	// For storing answers for each query( 1-based indexing ). 
	long long ans[q + 1]; 

	// traverse for numbers and query 
	for (long long i = 1; i <= n + q; ++i) { 
		if (a[i].pos != 0) { 

			// call function to returns answer for each query 
			long long cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1); 

			// This will ensure that answer of each query 
			// are stored in order it was initially asked. 
			ans[a[i].pos] = cnt; 
		} 
		else { 
			// a[i].r contains the position of the 
			// element in the original array. 
			update(BIT, n, a[i].r); 
		} 
	} 
	long long res=0;
	// Output the answer array 
	for (long long i = 1; i <= q; ++i) { 
		// cout<<ans[i]<<" \n";
		// cout << QueryR[i-1]-QueryL[i-1]+1- ans[i] << endl; 
		res+=(QueryR[i-1]-QueryL[i-1]+1- ans[i]);
	} 
	cout<<res<<"\n";
} 

// Driver Code 
int main() 
{ 
	long long n;
	cin>>n;
	long long a[n],b[n];
	for(long long i=0;i<n;i++){
	    cin>>a[i];
	}
	for(long long i=0;i<n;i++){
	    cin>>b[i];
	}
	long long arr[n];
	for(long long i=0;i<n;i++){
	   arr[i]=-a[i]+b[i];
	}

	// long long arr[] = { 7, 3, 9, 13, 5, 4 }; 
	// long long n = sizeof(arr) / sizeof(arr[0]); 

	// 1-based indexing 
	long long QueryL[n-1],QueryR[n-1],QueryK[n-1];
	for(long long i=0;i<n-1;i++){
		QueryL[i]=i+2;
		QueryR[i]=n;
		QueryK[i]=-arr[i]-1;
	}
	// for(auto x:arr){
	// 	cout<<x<<" ";
	// }
	// cout<<"\n";
	// for(auto x:QueryL){
	// 	cout<<x<<" ";
	// }
	// cout<<"\n";
	// for(auto x:QueryR){
	// 	cout<<x<<" ";
	// }
	// cout<<"\n";
	// for(auto x:QueryK){
	// 	cout<<x<<" ";
	// }
	// cout<<"\n";
	// long long QueryL[] = { 1, 2 }; 
	// long long QueryR[] = { 4, 6 }; 

	// k for each query 
	// long long QueryK[] = { 6, 8 }; 

	// number of queries 
	// long long q = sizeof(QueryL) / sizeof(QueryL[0]); 
	long long q=n-1;

	// Function call to get 
	solveQuery(arr, n, QueryL, QueryR, QueryK, q); 

	return 0; 
} 
