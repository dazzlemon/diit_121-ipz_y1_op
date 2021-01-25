//

struct Matrix {
	int n, m;//n - rows, m - columns
	float* items;

	float* frac_0_6;//pointer for array with sum of positive elements that have fraction <.6 for every row
	float frac_0_6_sum;//sum of frac_0_6 array

	void gen() {
		items = new float[n * m];
		for (int i = 0; i < (n * m); i++) {
			items[i] = round(((static_cast<float>(rand()) / RAND_MAX) * 2752 - 1002)) / 100;
			//items[i] = ((std::rand() % 2753) / 100.0) - 10.02;//gen rand num[-10.02;17.5]//old
		}
	}

	void print() {
		for (int i = 0, k = 0; i < n; i++) {
			for (int j = 0; j < m; j++, k++) {
				std::cout << std::setw(6) << items[k] << " | ";
			}
			std::cout << std::endl;
		}
	}

	void frac_find() {//make returnable?
		frac_0_6_sum = 0;
		frac_0_6 = new float[n];
		for (int i = 0; i < n; i++) {
			frac_0_6[i] = 0;
			for (int j = 0; j < m; j++) {
				if ((items[(i * m) + j] > 0) && ((items[(i * m) + j] - floor(items[(i * m) + j])) < 0.6)) {//floor returns whole part
					frac_0_6[i] += items[(i * m) + j];
				}
			}
			frac_0_6_sum += frac_0_6[i];
		}
	}

	int repdigit_amount() {
		int repdig_am = 0;
		for (int i = 0; i < (n * m); i++) {
			float temp = abs(items[i]);//abs returns absolute value of argument
			double fraction = modf(temp, &temp);//modf returns fractional part, whole to temp
			int fractint = static_cast<int>(round(fraction * 100));//round for kostil' fix 
			if ((fractint / 10) == (fractint % 10)) {//checking if both digits ==
				repdig_am++;
			}
		}
		return repdig_am;
	}

	void sort_rows() {
		bool sorted = false;
		for (int i = 0; !sorted && (i < (n - 1)); i++) {//i - #of iteration
			bool sorted = true;
			for (int j = 0; j < (n - i - 1); j++) {//j - #element being compared to next
				if (frac_0_6[j] > frac_0_6[j + 1]) {
					for (int k = 0; k < m; k++) {//k - #number of element being swapped
						float temp = items[(j * m) + k];
						items[(j * m) + k] = items[((j + 1) * m) + k];
						items[((j + 1) * m) + k] = temp;
					}

					float temp = frac_0_6[j];
					frac_0_6[j] = frac_0_6[j + 1];
					frac_0_6[j + 1] = temp;

					sorted = false;
				}
			}
		}
	}

	void del_even_rows() {
		n = (n / 2) + (n % 2);
		float* temp = new float[n * m];
		for (int i = 0; i < n; i++) {//row iterator
			for (int j = 0; j < m; j++) {//element iterator
				temp[(i * m) + j] = items[(2 * i * m) + j];
			}
		}
		delete[]items;
		items = temp;
	}

	void delete_ () {//deletes matrix
		delete[]items;
	}
};

struct Matrix_v2 {
	int n, m;//n - rows, m - columns
	float** items;

	float* frac_0_6;//pointer for array with sum of positive elements that have fraction <.6 for every row
	float frac_0_6_sum;//sum of frac_0_6 array

	void gen() {
		items = new float*[n];
		for (int i = 0; i < n; i++) {
			items[i] = new float[m];
			for (int j = 0; j < m; j++) {
				items[i][j] = round(((static_cast<float>(rand()) / RAND_MAX) * 2752 - 1002)) / 100;
				//items[i] = ((std::rand() % 2753) / 100.0) - 10.02;//gen rand num[-10.02;17.5]//old
			}
		}
	}

	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cout << std::setw(6) << items[i][j] << " | ";
			}
			std::cout << std::endl;
		}
	}

	void frac_find() {//make returnable?
		frac_0_6_sum = 0;
		frac_0_6 = new float[n];
		for (int i = 0; i < n; i++) {
			frac_0_6[i] = 0;
			for (int j = 0; j < m; j++) {
				if ((items[i][j] > 0) && ((items[i][j] - floor(items[i][j])) < 0.6f)) {//floor returns whole part, 0.6f because 0.6 ~= 0.5(9) aka 0.6 - 0, and 0.6f ~= 0.6(0) aka 0.6 + 0// no casting to float from double, more consistent
					frac_0_6[i] += items[i][j];
				}
			}
			frac_0_6_sum += frac_0_6[i];
		}
	}

	int repdigit_amount() {
		int repdig_am = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				float temp = abs(items[i][j]);//abs returns absolute value of argument
				double fraction = modf(temp, &temp);//modf returns fractional part, whole to temp
				int fractint = static_cast<int>(round(fraction * 100));//round for kostil' fix 
				if ((fractint / 10) == (fractint % 10)) {//checking if both digits ==
					repdig_am++;
				}
			}
		}
		return repdig_am;
	}

	void sort_rows() {
		bool sorted = false;
		for (int i = 0; !sorted && (i < (n - 1)); i++) {//i - #of iteration
			bool sorted = true;
			for (int j = 0; j < (n - i - 1); j++) {//j - #element being compared to next and row aswell
				if (frac_0_6[j] > frac_0_6[j + 1]) {
					for (int k = 0; k < m; k++) {//k - #number of element being swapped
						float temp = items[j][k];
						items[j][k] = items[j + 1][k];
						items[j + 1][k] = temp;
					}

					float temp = frac_0_6[j];
					frac_0_6[j] = frac_0_6[j + 1];
					frac_0_6[j + 1] = temp;

					sorted = false;
				}
			}
		}
	}

	void del_even_rows() {
		float** temp = new float* [(n / 2) + (n % 2)];
		
		if ((n % 2) == 0) {
			temp[(n / 2) + (n % 2) - 1] = items[n - 2];
		}
		else {
			temp[(n / 2) + (n % 2) - 1] = items[n - 1];
		}

		for (int i = 0; i < (n - 2); i += 2) {
			temp[i / 2] = items[i];
			delete[]items[i + 1];
		}

		n = (n / 2) + (n % 2);
		delete[]items;
		items = temp;
	}

	void delete_() {//deletes matrix
		for (int i = 0; i < n; i++) {
			delete[]items[i];
		}
		delete[]items;
	}
};