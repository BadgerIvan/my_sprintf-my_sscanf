#ifndef TEST_H_
#define TEST_H_

#include <check.h>

Suite *my_memcpy_suite(void);
Suite *my_strlen_suite(void);
Suite *my_memset_suite(void);
Suite *my_strncpy_suite(void);
Suite *my_strchr_suite(void);
Suite *my_strstr_suite(void);

Suite *numeric_parsing_suite(void);
Suite *my_size_t_to_string_suite(void);
Suite *long_double_to_string_suite(void);
Suite *long_double_to_scientific_suite(void);

Suite *my_sprintf_basic_suite(void);
Suite *my_sprintf_c_suite(void);
Suite *my_sprintf_s_suite(void);
Suite *my_sprintf_di_suite(void);
Suite *my_sprintf_n_suite(void);
Suite *my_sprintf_percent_suite(void);
Suite *my_sprintf_u_suite(void);
Suite *my_sprintf_x_suite(void);
Suite *my_sprintf_X_suite(void);
Suite *my_sprintf_o_suite(void);
Suite *my_sprintf_p_suite(void);
Suite *my_sprintf_f_suite(void);
Suite *my_sprintf_F_suite(void);
Suite *my_sprintf_e_suite(void);
Suite *my_sprintf_E_suite(void);
Suite *my_sprintf_g_suite(void);
Suite *my_sprintf_G_suite(void);

Suite *my_sscanf_basic_suite(void);
Suite *my_sscanf_d_suite(void);
Suite *my_sscanf_x_X_suite(void);
Suite *my_sscanf_o_suite(void);
Suite *my_sscanf_i_suite(void);
Suite *my_sscanf_u_suite(void);
Suite *my_sscanf_c_suite(void);
Suite *my_sscanf_s_suite(void);
Suite *my_sscanf_f_suite(void);
Suite *my_sscanf_F_suite(void);
Suite *my_sscanf_e_suite(void);
Suite *my_sscanf_E_suite(void);
Suite *my_sscanf_g_suite(void);
Suite *my_sscanf_G_suite(void);
Suite *my_sscanf_n_suite(void);
Suite *my_sscanf_percent_suite(void);

#endif