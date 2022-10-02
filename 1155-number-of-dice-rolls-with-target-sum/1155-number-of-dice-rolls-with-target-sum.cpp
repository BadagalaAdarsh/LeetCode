	int solution3(int n, int k, int target) {
		if (n * k < target) return 0;
		mem.assign(n + 1, vector<int>(target + 1, -1));
		return f(n, k, target);
	}

	// 35 ms, faster than 69.33% : 8.3 MB, less than 59.18%
	int solution2(int n, int k, int target) {
		mem.assign(n + 1, vector<int>(target + 1, -1));
		return f(n, k, target);
	}
	const int MOD = 1e9 + 7;
	vector<vector<int>> mem;
	int f(int n, int k, int val) {
		if (val < 0) return 0;
		if (n == 0 && val == 0) return 1;
		if (n == 0) return 0;
		if (mem[n][val] != -1) return mem[n][val];

		//Printer::print(n, val);
		int ret = 0;
		for (size_t i = 1; i <= k; i++)
		{
			ret += f(n - 1, k, val - i);
			ret %= MOD;
		}

		return mem[n][val] = ret;
	}
	
	// Tabulation 
	// 10 ms, faster than 96.63% : 6.5 MB, less than 72.78%
	int solution4(int n, int k, int target) {
		if (n * k < target) return 0;
		vector<vector<int>> mem(n + 1, vector<int>(target + 1, 0));

		mem[0][0] = 1;

		for (int i = 1; i < n + 1; i++)
		{
			for (int val = 1; val < target + 1; val++)
			{
				int ret = 0;
				for (int j = 1; j <= k; j++)
				{
					if (val - j >= 0)
						ret += mem[i - 1][val - j], ret %= MOD;
				}
				mem[i][val] = ret;
			}
		}
		//Printer::print(mem);
		return mem[n][target];
	}
	
	// Tabulation Optimization 
	// 7 ms, faster than 97.83% : 6.2 MB, less than 76.82%
	int solution(int n, int k, int target) {
		if (n * k < target) return 0;
		vector<vector<int>> mem(2, vector<int>(target + 1, 0));

		int cur = 1, other = 0;
		mem[0][0] = 1;

		for (int i = 1; i < n + 1; i++)
		{
			for (int val = 1; val < target + 1; val++)
			{
				int ret = 0;
				for (int j = 1; j <= k; j++)
				{
					if (val - j >= 0)
						ret += mem[other][val - j], ret %= MOD;
				}
				mem[cur][val] = ret;
			}
			cur = other;
			other = 1 - other;
			mem[cur][0] = 0;
		}
		//Printer::print(mem);
		return mem[other][target];
	}
