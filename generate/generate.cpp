#include <algorithm>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Note {
    int time = -1;
    string value = "";
    int duration = -1;
    int duty = -1;
    int volume = -1;
};

deque<vector<Note>> parseFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    deque<vector<Note>> result;

    vector<Note> notes;
    regex propertyPattern("([a-zA-Z]+)=\"([^\"]*)\"");
    string line;
    int base_time = -1;

    while (getline(file, line)) {
        // remove leading tabs and spaces from line
        line.erase(line.begin(), find_if(line.begin(), line.end(),
                                         [](int ch) { return !isspace(ch); }));

        if (line.empty() || line.find("PatternInstance") != std::string::npos) {
            continue;
        }

        if (line.find("Channel") != std::string::npos) {
            result.push_back(notes);
            notes.clear();
            base_time = -1;
            continue;
        }

        // if line starts with "Pattern", then it is a pattern line
        if (line.find("Pattern") == 0) {
            base_time += 1;
            // get the pattern name
            size_t pos = line.find('=');
            string patternName = line.substr(pos + 2, line.size() - pos - 3);
            continue;
        }

        // if line does not start with "Note", skip it
        if (line.find("Note") != 0) {
            continue;
        }

        Note note;
        smatch match;
        string::const_iterator searchStart(line.cbegin());

        while (regex_search(searchStart, line.cend(), match, propertyPattern)) {
            string propertyName = match[1];
            string propertyValue = match[2];

            if (propertyName == "Time") {
                note.time = stoi(propertyValue);
            } else if (propertyName == "Value") {
                note.value = propertyValue;
            } else if (propertyName == "Duration") {
                note.duration = stoi(propertyValue);
            } else if (propertyName == "Instrument") {
                // Instrument can be "Duty 0", "Duty 1", "Duty 2" or "Duty 3"
                note.duty = stoi(propertyValue.substr(5));
            } else if (propertyName == "Volume") {
                note.volume = stoi(propertyValue);
            }

            searchStart = match.suffix().first;
        }

        note.time += base_time * 256;

        notes.push_back(note);
    }

    result.push_back(notes);

    result.pop_front();

    return result;
}

int main() {
    vector<string> ARRAY_NAMES = {"SQUARE1_NOTES", "SQUARE2_NOTES",
                                  "TRIANGLE_NOTES", "NOISE_NOTES"};
    vector<string> ARRAY_LENGTH_NAMES = {
        "SQUARE1_NOTES_LENGTH", "SQUARE2_NOTES_LENGTH", "TRIANGLE_NOTES_LENGTH",
        "NOISE_NOTES_LENGTH"};

    const string OUTPUT_FOLDER = "output/";

    vector<string> OUTPUT_FILES = {"square1.c", "square2.c", "triangle.c",
                                   "noise.c"};

    deque<vector<Note>> result = parseFile("mario.txt");

    for (int i = 0; i < 4; i++) {
        filesystem::create_directories(OUTPUT_FOLDER);

        // open output file
        ofstream output(OUTPUT_FOLDER + OUTPUT_FILES[i]);
        if (!output.is_open()) {
            cerr << "Error opening file: " << OUTPUT_FILES[i] << endl;
            exit(1);
        }

        auto &notes = result[i];
        auto &ARRAY_NAME = ARRAY_NAMES[i];
        auto &ARRAY_LENGTH_NAME = ARRAY_LENGTH_NAMES[i];
        output << "#include \"../notes.h\"\n\nconst note_t " << ARRAY_NAME
               << "[]={\n";

        for (auto note : notes) {
            output << "{\"" << note.value << "\", " << note.time << ", "
                   << note.duration << ", " << note.duty << ", " << note.volume
                   << "}," << endl;
        }

        output << "};\n";

        output << "const size_t " << ARRAY_LENGTH_NAME << " = sizeof("
               << ARRAY_NAME << ") / sizeof(" << ARRAY_NAME << "[0]);\n";

        output.close();
    }

    return 0;
}
