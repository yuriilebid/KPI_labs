#include <string>

using namespace std;

class carry_truck {
private:
	char *name;
	uint16_t galons_use;
	uint16_t power;
	uint16_t max_weight;
    uint32_t miles_history;
public:
    // Default constructor
	carry_truck();

    // Constructor of initialization
	carry_truck(const char* name, uint16_t galons_use_input, uint16_t power_input,
		        uint16_t max_weight_input, uint32_t miles_history_input);

    // Copy constructor
    carry_truck(const carry_truck &car);

    // Destructor
    ~carry_truck();

    uint16_t get_galons_use();

    uint16_t get_power();

    uint32_t get_miles_history();

    uint16_t get_max_weight();

    char* get_name();

    void set_name(const char* name);

    void set_galons_use(uint16_t input);

    void set_power(uint16_t input);

    void set_miles_history(uint32_t input);

    void set_max_weight(uint16_t input);

    void increase_power(int value_to_increase);

    void show_object(); 
};
