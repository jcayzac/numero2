#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

static const vector<vector<string>> groups = {
{"Amelia", "Ayame", "Amélia", "Emily", "Émilie", "Mélanie", "Melany", "Mélissa", "Melissa", "Melody", "Mélodie"},
{"Carin", "Carine", "Karin", "Karine"},
{"Lucy", "Luce"},
{"May", "Mai", "Mei", "Maya"},
{"Nora", "Norah"},
{"Violet", "Violette"},
{"Clémentine"},
{"Chloé"},
{"Daphnée"},
{"Élodie"},
{"Olivia"},
{"Rika"},
{"Miko"},
{"Kei"},
{"Rose"},
{"Iris"},
{"Yuzu"},
{"Zoé"}
};

int main() {
	// All the names, sorted
	vector<string> names;
	// All the names in the same group as the key
	map<string, vector<string>> equivalents;
	for (const auto& group : groups) {
		names.insert(names.end(), group.begin(), group.end());
		for (auto it(group.begin()); it != group.end(); ++it) {
			vector<string> equiv(group.begin(), it);
			auto next = it + 1;
			if (next != group.end()) equiv.insert(equiv.end(), next, group.end());
			sort(equiv.begin(), equiv.end());
			equivalents[*it] = equiv;
		}
	}
	sort(names.begin(), names.end());

	for (const auto& name1 : names) {
		const auto& equiv1(equivalents[name1]);

		for (const auto& name2 : names) {
			const auto& equiv2(equivalents[name2]);
			if (name1 == name2) continue;
			if (find(equiv1.begin(), equiv1.end(), name2) != equiv1.end()) continue;

			cout << name1 << " " << name2 << "\n";

			for (const auto& name3 : names) {

				if (name3 == name1 || name3 == name2) continue;
				if (find(equiv1.begin(), equiv1.end(), name3) != equiv1.end()) continue;
				if (find(equiv2.begin(), equiv2.end(), name3) != equiv2.end()) continue;

				cout << name1 << " " << name2 << " " << name3 << "\n";
			}
		}
	}

	return 0;
}

