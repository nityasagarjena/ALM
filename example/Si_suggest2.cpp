/*
 suggest_Si.cpp

 This is an example to run ALM in the suggest mode.

*/

#include "alm.h"
#include <iostream>
#include <string>

void show_disp_patterns(const int fc_order,
                        ALM_NS::ALM *alm)
{
    const int num_patterns = alm->get_number_of_displacement_patterns(fc_order);
    int numbers[num_patterns];
    int total_num_disps = 0;
    alm->get_number_of_displaced_atoms(numbers, fc_order);
    for (int i = 0; i < num_patterns; i++) {
        total_num_disps += numbers[i];
    }
    int atom_indices[total_num_disps];
    double disp_patterns[total_num_disps * 3];
    const int basis = alm->get_displacement_patterns(atom_indices,
                                                     disp_patterns,
                                                     fc_order);

    const std::string str_basis[2] = {"Cartesian", "Fractional"};
    std::cout << "Basis: " << str_basis[basis] << std::endl;
    int i_atom = 0;
    int i_disp = 0;
    for (int i = 0; i < num_patterns; i++) {
        std::cout << i + 1 << " : " << numbers[i] << std::endl;
        for (int j = 0; j < numbers[i]; j++) {
            std::cout << "  " << atom_indices[i_atom] + 1  << " : ";
            ++i_atom;
            std::cout << disp_patterns[i_disp] << " "; ++i_disp;
            std::cout << disp_patterns[i_disp] << " "; ++i_disp;
            std::cout << disp_patterns[i_disp] << std::endl; ++i_disp;
        }
    }
}

int main()
{
    ALM_NS::ALM *alm = new ALM_NS::ALM();

    double lavec[3][3] = {{20.406, 0, 0},
                          {0, 20.406, 0},
                          {0, 0, 20.406}};
    double xcoord[][3] =
        {{ 0.0000000000000000, 0.0000000000000000, 0.0000000000000000},
         { 0.0000000000000000, 0.0000000000000000, 0.5000000000000000},
         { 0.0000000000000000, 0.2500000000000000, 0.2500000000000000},
         { 0.0000000000000000, 0.2500000000000000, 0.7500000000000000},
         { 0.0000000000000000, 0.5000000000000000, 0.0000000000000000},
         { 0.0000000000000000, 0.5000000000000000, 0.5000000000000000},
         { 0.0000000000000000, 0.7500000000000000, 0.2500000000000000},
         { 0.0000000000000000, 0.7500000000000000, 0.7500000000000000},
         { 0.1250000000000000, 0.1250000000000000, 0.1250000000000000},
         { 0.1250000000000000, 0.1250000000000000, 0.6250000000000000},
         { 0.1250000000000000, 0.3750000000000000, 0.3750000000000000},
         { 0.1250000000000000, 0.3750000000000000, 0.8750000000000000},
         { 0.1250000000000000, 0.6250000000000000, 0.1250000000000000},
         { 0.1250000000000000, 0.6250000000000000, 0.6250000000000000},
         { 0.1250000000000000, 0.8750000000000000, 0.3750000000000000},
         { 0.1250000000000000, 0.8750000000000000, 0.8750000000000000},
         { 0.2500000000000000, 0.0000000000000000, 0.2500000000000000},
         { 0.2500000000000000, 0.0000000000000000, 0.7500000000000000},
         { 0.2500000000000000, 0.2500000000000000, 0.0000000000000000},
         { 0.2500000000000000, 0.2500000000000000, 0.5000000000000000},
         { 0.2500000000000000, 0.5000000000000000, 0.2500000000000000},
         { 0.2500000000000000, 0.5000000000000000, 0.7500000000000000},
         { 0.2500000000000000, 0.7500000000000000, 0.0000000000000000},
         { 0.2500000000000000, 0.7500000000000000, 0.5000000000000000},
         { 0.3750000000000000, 0.1250000000000000, 0.3750000000000000},
         { 0.3750000000000000, 0.1250000000000000, 0.8750000000000000},
         { 0.3750000000000000, 0.3750000000000000, 0.1250000000000000},
         { 0.3750000000000000, 0.3750000000000000, 0.6250000000000000},
         { 0.3750000000000000, 0.6250000000000000, 0.3750000000000000},
         { 0.3750000000000000, 0.6250000000000000, 0.8750000000000000},
         { 0.3750000000000000, 0.8750000000000000, 0.1250000000000000},
         { 0.3750000000000000, 0.8750000000000000, 0.6250000000000000},
         { 0.5000000000000000, 0.0000000000000000, 0.0000000000000000},
         { 0.5000000000000000, 0.0000000000000000, 0.5000000000000000},
         { 0.5000000000000000, 0.2500000000000000, 0.2500000000000000},
         { 0.5000000000000000, 0.2500000000000000, 0.7500000000000000},
         { 0.5000000000000000, 0.5000000000000000, 0.0000000000000000},
         { 0.5000000000000000, 0.5000000000000000, 0.5000000000000000},
         { 0.5000000000000000, 0.7500000000000000, 0.2500000000000000},
         { 0.5000000000000000, 0.7500000000000000, 0.7500000000000000},
         { 0.6250000000000000, 0.1250000000000000, 0.1250000000000000},
         { 0.6250000000000000, 0.1250000000000000, 0.6250000000000000},
         { 0.6250000000000000, 0.3750000000000000, 0.3750000000000000},
         { 0.6250000000000000, 0.3750000000000000, 0.8750000000000000},
         { 0.6250000000000000, 0.6250000000000000, 0.1250000000000000},
         { 0.6250000000000000, 0.6250000000000000, 0.6250000000000000},
         { 0.6250000000000000, 0.8750000000000000, 0.3750000000000000},
         { 0.6250000000000000, 0.8750000000000000, 0.8750000000000000},
         { 0.7500000000000000, 0.0000000000000000, 0.2500000000000000},
         { 0.7500000000000000, 0.0000000000000000, 0.7500000000000000},
         { 0.7500000000000000, 0.2500000000000000, 0.0000000000000000},
         { 0.7500000000000000, 0.2500000000000000, 0.5000000000000000},
         { 0.7500000000000000, 0.5000000000000000, 0.2500000000000000},
         { 0.7500000000000000, 0.5000000000000000, 0.7500000000000000},
         { 0.7500000000000000, 0.7500000000000000, 0.0000000000000000},
         { 0.7500000000000000, 0.7500000000000000, 0.5000000000000000},
         { 0.8750000000000000, 0.1250000000000000, 0.3750000000000000},
         { 0.8750000000000000, 0.1250000000000000, 0.8750000000000000},
         { 0.8750000000000000, 0.3750000000000000, 0.1250000000000000},
         { 0.8750000000000000, 0.3750000000000000, 0.6250000000000000},
         { 0.8750000000000000, 0.6250000000000000, 0.3750000000000000},
         { 0.8750000000000000, 0.6250000000000000, 0.8750000000000000},
         { 0.8750000000000000, 0.8750000000000000, 0.1250000000000000},
         { 0.8750000000000000, 0.8750000000000000, 0.6250000000000000}};
    const int nat = 64;
    int kd[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::string kdname[] = {"Si"};
    const int fc_order = 2;

    alm->set_verbosity(0);
    alm->set_run_mode("suggest");
    alm->set_output_filename_prefix("si222API");
    alm->set_cell(nat, lavec, xcoord, kd, kdname);
    alm->set_norder(fc_order);
    double rcs[fc_order] = {-1, 7.3};
    alm->set_cutoff_radii(rcs);
    alm->run();

    std::cout << "************ ALM API ************" << std::endl;
    std::cout << "Atom mapping from primitive to supercell:" << std::endl;
    int map_p2s[nat];
    const int num_trans = alm->get_atom_mapping_by_pure_translations(map_p2s);
    std::cout << "Number of translations: " << num_trans << std::endl;
    for (int i = 0; i < num_trans; ++i) {
        std::cout << i + 1 << " [ ";
        for (int j = 0; j < nat / num_trans; ++j) {
            std::cout << map_p2s[i * (nat / num_trans) + j] + 1 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Displacement patterns:" << std::endl;
    for (int i = 1; i < 3; ++i) {
        show_disp_patterns(i, alm);
    }
    std::cout << "************ ALM API ************" << std::endl;

    delete alm;

    return 1;
}
