    const int ALPH = 256; 
    int n = (int)s.size();
    int best = 0;

    for (int k = 1; k <= min(26, n); ++k) {
        for (int f = 1; k * f <= n; ++f) {
            int win = k * f;
            vector<int> cnt(ALPH, 0);
            int distinct = 0;      
            int eqf = 0;           

            auto add = [&](unsigned char c) {
                int prev = cnt[c]++;
                if (prev == 0) distinct++;
                if (prev + 1 == f) eqf++;
                else if (prev == f) eqf--;
            };
            auto remove_c = [&](unsigned char c) {
                int prev = cnt[c]--;
                if (prev == 1) distinct--;
                if (prev == f) eqf--;     
                else if (prev - 1 == f) eqf++; 
            };

            for (int i = 0; i < win && i < n; ++i) add((unsigned char)s[i]);
            if (win <= n && distinct == k && eqf == k)
                best = max(best, win);

            for (int r = win; r < n; ++r) {
                add((unsigned char)s[r]);
                remove_c((unsigned char)s[r - win]);
                if (distinct == k && eqf == k)
                    best = max(best, win);
            }
        }
    }
    return best;