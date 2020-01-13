class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int sumleft = 0;
		int sumright = 0;
		int minleft = INT_MAX;
		int minright = INT_MAX;
		int color = 0;
		for (int i = 0; i<n; i++){
			if (left[i] * right[i] == 0){
				color += left[i] + right[i];
			}
			else{
				sumleft += left[i];
				sumright += right[i];
				minleft = min(minleft, left[i]);
				minright = min(minright, right[i]);

			}


		}
		return color + min(sumleft - minleft + 1, sumright - minright + 1) + 1;
	}
};