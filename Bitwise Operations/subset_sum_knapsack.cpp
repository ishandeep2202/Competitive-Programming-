// You are given N≤1000 items, each with some weight wi. Is there a subset of items with total weight exactly W≤10^6?

bitset<MAX_W> can;
int main() {
	int n, W;
	cin >> n >> W;
	can[0] = true;
	for(int id = 0; id < n; id++) {
		int x;
		cin >> x;
		can = can | (can << x); // or just: can |= (can << x);
	}
	cout << (can[W] ? "YES" : "NO") << endl;
}
