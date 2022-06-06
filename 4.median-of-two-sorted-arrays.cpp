class Solution {
public:
    typedef long long Long;
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        Long N1 = v1.size(), N2 = v2.size();
        Long N = N1 + N2, mid = N/2;
        if (N1 == 0)
            return single(v2, N, mid);
        else if (N2 == 0)
            return single(v1, N, mid);
		else if (N1 == 1) {
			return one_elm(v1[0], v2, N, mid);
		}
		else if (N2 == 1) {
			return one_elm(v2[0], v1, N, mid);
		}

        Long l1 = -1, r1 = -1, l2 = -1, r2 = -1;
		Long sum, i1 = -1, i2 = -1;
		int s1, s2;
        int sl1 = v1[0], sl2 = v2[0], sr1 = v1[N1-1], sr2 = v2[N2-1];
        if (sr1 <= sl2) {
            return simple(v1, v2, N, mid);
        }
        else if (sr2 <= sl1) {
            return simple(v2, v1, N, mid);
        }
        
        if (sl1 < sl2) {
            l1 = 0;
            if (sr2 < sr1) {
                r1 = N1-1;
            }
            else if (sr1 < sr2) {
                r2 = N2-1;
                sum = N1-1;
                if (sum < mid) {
					l2 = 0;
				}
                else if (sum > mid)
                    r1 = N1-1;
				else {
					r1 = N1-1; l2 = 0;
				}
            }
            else {
                r1 = N1-1; r2 = N2-1;
            }
        }
        else if (sl2 < sl1) {
            l2 = 0;
            if (sr2 < sr1) {
                r1 = N1-1;
				sum = N2-1;
				if (sum < mid) {
					l1 = 0;
				}
				else if (sum > mid) {
					r2 = N2-1;
				}
				else {
					l1 = 0; r2 = N2-1;
				}
            }
            else if (sr1 < sr2) {
                r2 = N2-1;
            }
            else {
                r1 = N1-1; r2 = N2-1;
            }
        }
        else { // sl1 == sl2
            l1 = l2 = 0;
            if (sr2 < sr1) {
                r1 = N1-1;
            }
            else if (sr1 < sr2) {
                r2 = N2-1;
            }
            else { // sr1 == sr2
                r1 = N1-1; r2 = N2-1;
            }
        }
        
        while (true) {
			if (r1 - l1 == 1) {
                try {
					return converge_2(v1, v2, l1, r1, l2, r2, i1, i2, N2, N, mid);
				}
				catch (int) {
					continue;
				}
			}
			if (r2 - l2 == 1) {
                try {
					return converge_2(v2, v1, l2, r2, l1, r1, i2, i1, N1, N, mid);
				}
				catch (int) {
					continue;
				}
            }

            if (l1 < 0 || r1 < 0) {
				try {
					return boundary(v1, v2, l1, r1, l2, r2, i1, i2, N1, N, mid);
				}
				catch (int) {
					continue;
				}
            }
			else if (l2 < 0 || r2 < 0) {
				try {
					return boundary(v2, v1, l2, r2, l1, r1, i2, i1, N2, N, mid);
				}
				catch (int) {
					continue;
				}
			}
            
            if (i1 < 0)
                i1 = (l1 + r1)/2;
            if (i2 < 0)
                i2 = (l2 + r2)/2;
            s1 = v1[i1], s2 = v2[i2];
            cout << "s1 = " << s1 << " s2 = " << s2 << endl;
            sum = i1 + i2;
            if (sum > mid) {
                if (s1 < s2) {
                    r2 = i2; i2 = -1;
                }
                else if (s2 < s1) {
                    r1 = i1; i1 = -1;
                }
            }
            else if (sum < mid) {
                if (s1 < s2) {
                    l1 = i1; i1 = -1;
                }
                else if (s2 < s1) {
                    l2 = i2; i2 = -1;
                }
                else {
                    l1 = i1; i1 = -1; l2 = i2; i2 = -1;
                }
            }
            else {
                if (s1 < s2) {
                    l1 = i1; i1 = -1;
                    r2 = i2; i2 = -1;
                }
                else if (s2 < s1) {
                    r1 = i1; i1 = -1;
                    l2 = i2; i2 = -1;
                }
                else { // s1 == s2
                    if (N & 1)
                        return s1;
                    else {
                        int s11 = v1[i1-1], s21 = v2[i2-1];
                        if (s11 < s21)
                            return (s21 + s2)/2.;
                        else
                            return (s11 + s1)/2.;
                    }
                }
            }
        }
    }

	double boundary(const vector<int> &v1, const vector<int> &v2, Long &l1, Long &r1, Long &l2, Long &r2, Long &i1, Long &i2, Long N1, Long N, Long mid)
	{
		int s1, s2, sum;
		i2 = (l2 + r2)/2;
		if (l1 < 0) {
			s1 = v1[0]; s2 = v2[i2];
			sum = 0 + i2;
			if (sum < mid) {
				if (s1 < s2) {
					l1 = 0;
				}
				else if (s2 < s1) {
					l2 = i2; i2 = -1;
				}
				else {
					l1 = 0; l2 = i2; i2 = -1;
				}
			}
			else if (sum > mid) {
				if (s1 < s2) {
					r2 = i2; i2 = -1;
				}
				else {
					return single(v2, N, mid);
				}
			}
			else {
				if (s1 < s2) {
					l1 = 0;
					r2 = i2; i2 = -1;
				}
				else {
					l2 = i2; i2 = -1;
				}
			}
		}
		else if (r1 < 0) {
			s1 = v1[N1-1]; s2 = v2[i2];
			sum = N1-1 + i2;
			if (sum < mid) {
				if (s1 <= s2) {
					if (N & 1)
						return simple(v1, v2, N, mid);
					else {
						return (max(v1[N1-1],v2[mid-N1-1]) + v2[mid-N1])/2.;
					}
				}
				else {
					l2 = i2; i2 = -1;
				}
			}
			else if (sum > mid) {
				if (s1 < s2) {
					r2 = i2; i2 = -1;
				}
				else if (s2 < s1) {
					r1 = N1-1;
				}
				else {
					r1 = N1-1; r2 = i2; i2 = -1;
				}
			}
			else {
				if (s2 < s1) {
					l2 = i2; i2 = -1;
					r1 = N1-1;
				}
				else {
					r2 = i2; i2 = -1;
				}
			}
		}
		throw 898;
	}

	double converge_2(const vector<int> &v1, const vector<int> &v2, Long l1, Long r1, Long &l2, Long &r2, Long &i1, Long &i2, Long N2, Long N, Long mid)
	{
		int s2, sum, sl1, sr1;
		if (l2 < 0) {
			if (r2 < 0) {
				if (v2[0] < v1[l1]) {
					l2 = 0; throw 898;
				}
				if (v2[N2-1] > v1[r1]) {
					r2 = N2-1; throw 898;
				}
				if (l1 == mid) {
					if (N & 1)
						return v1[l1];
					else
						return (v1[l1] + v1[l1-1])/2.;
				}
				else if  (r1 + N2 == mid) {
					if (N & 1)
						return v1[r1];
					else
						return (v2[N2-1] + v1[r1])/2.;
				}
				else if (l1 == mid -1) {
					if (N & 1)
						return v2[0];
					else
						return (v1[l1] + v2[0])/2.;
				}
				else
					return single(v2, N, mid, l1+1);
			}
			else {
				if (mid <= l1) {
					return single(v1, N, mid);
				}
				else if (l1 + 1 == mid) {
					if (N & 1)
						return v1[l1];
					else
						return (v1[l1-1]+v2[l1])/2.;
				}
				else {
					l2 = 0; throw 898;
				}
			}
		}
		else if (r2 < 0) {
			if (N2 + r1 == mid) {
				if (N & 1)
					return v1[r1];
				else
					return (v2[N2-1]+v1[r1])/2.;
			}
			else {
				r2 = N2-1; throw 898;
			}
		}
		if (r2 - l2 == 1)
			return finalize(v1, v2, l1, r1, l2, r2, N, mid);
		if (i2 < 0)
			i2 = (l2 + r2)/2;
		s2 = v2[i2];
		sl1 = v1[l1]; sr1 = v1[r1];
		if (s2 < sl1) {
			l2 = i2; i2 = -1;
		}
		else if (s2 > sr1) {
			r2 = i2; i2 = -1;
		}
		else {
			sum = l1 + i2 + 1;
			if (sum < mid) {
				l2 = i2; i2 = -1;
			}
			else if (sum > mid) {
				r2 = i2; i2 = -1;
			}
			else {
				if (N & 1)
					return v2[i2];
				else
					return (max(v1[l1], v2[i2-1]) + v2[i2])/2.;
			}
		}
        throw 898;
	}

	double one_elm(int s1, vector<int> &v2, Long N, Long mid)
	{
        if (v2.size() == 1)
            return (s1 + v2[0])/2.;
		int s2 = v2[mid];
		if (N & 1) {
			if (s1 < s2) {
				s2 = v2[mid-1];
				if (s1 < s2)
					return s2;
				else
					return s1;
			}
			else // s1 >= s2
				return s2;
		}
		else {
			int s3 = v2[mid-1];
			if (s1 >= s2)
				return (s2 + s3)/2.;
			int s4 = v2[mid-2];
			if (s1 <= s4)
				return (s3 + s4)/2.;
			return (s1 + s3)/2.;
		}
	}

	double single(const vector<int> &v, Long N, Long mid, Long shift = 0)
    {
		Long ind = mid - shift;
		if (N & 1) {
            return v[ind];
        }
        else {
            return (v[ind] + v[ind-1])/2.;
        }
    }
    
	// v1.back() <= v2[0]
    double simple(const vector<int> &v1, const vector<int> &v2, Long N, Long mid)
    {
        if (N & 1) {
            if (mid < v1.size())
                return v1[mid];
            else
                return v2[mid-v1.size()];
        }
		else {
            if (mid < v1.size())
                return (v1[mid] + v1[mid-1])/2.;
            else if (mid > v1.size())
                return (v2[mid-v1.size()] + v2[mid-v1.size()-1])/2.;
            else
                return (v1.back() + v2[0])/2.;
        }
    }
    
	// r1-l1 == r2-l2 == 1
    double finalize(const vector<int> &v1, const vector<int> &v2, Long l1, Long r1, Long l2, Long r2, Long N, Long mid)
    {
        int sl1 = v1[l1], sr1 = v1[r1], sl2 = v2[l2], sr2 = v2[r2];
        if (N & 1) {
            if (l1 + l2 + 1 == mid) {
                return max(sl1, sl2);
            }
            else {
                return min(sr1, sr2);
            }
        }
        else {
            if (l1 + l2 + 1 == mid) {
                if (sl1 < sl2) {
                    if (l2 > 0)
                        return (max(sl1, v2[l2-1]) + sl2)/2.;
                    else
                        return (sl1 + sl2)/2.;
                }
                else {
                    if (l1 > 0)
                        return (max(sl2, v1[l1-1]) + sl1)/2.;
                    else
                        return (sl2 + sl1)/2.;
                }
            }
            else {
                return (max(sl1, sl2) + min(sr1, sr2))/2.;
            }
        }
    }
};
