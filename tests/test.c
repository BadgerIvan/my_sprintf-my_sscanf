#include "test.h"

#include <check.h>
#include <stdlib.h>

int main(void) {
  int number_failed;
  SRunner *sr = srunner_create(NULL);

  srunner_add_suite(sr, my_strlen_suite());
  srunner_add_suite(sr, my_memcpy_suite());
  srunner_add_suite(sr, my_memset_suite());
  srunner_add_suite(sr, my_strncpy_suite());
  srunner_add_suite(sr, my_strchr_suite());
  srunner_add_suite(sr, my_strstr_suite());

  srunner_add_suite(sr, numeric_parsing_suite());
  srunner_add_suite(sr, my_size_t_to_string_suite());
  srunner_add_suite(sr, long_double_to_string_suite());
  srunner_add_suite(sr, long_double_to_scientific_suite());

  srunner_add_suite(sr, my_sprintf_basic_suite());
  srunner_add_suite(sr, my_sprintf_c_suite());
  srunner_add_suite(sr, my_sprintf_s_suite());
  srunner_add_suite(sr, my_sprintf_di_suite());
  srunner_add_suite(sr, my_sprintf_n_suite());
  srunner_add_suite(sr, my_sprintf_percent_suite());
  srunner_add_suite(sr, my_sprintf_u_suite());
  srunner_add_suite(sr, my_sprintf_x_suite());
  srunner_add_suite(sr, my_sprintf_X_suite());
  srunner_add_suite(sr, my_sprintf_o_suite());
  srunner_add_suite(sr, my_sprintf_p_suite());
  srunner_add_suite(sr, my_sprintf_f_suite());
  srunner_add_suite(sr, my_sprintf_F_suite());
  srunner_add_suite(sr, my_sprintf_e_suite());
  srunner_add_suite(sr, my_sprintf_E_suite());
  srunner_add_suite(sr, my_sprintf_g_suite());
  srunner_add_suite(sr, my_sprintf_G_suite());

  srunner_add_suite(sr, my_sscanf_basic_suite());
  srunner_add_suite(sr, my_sscanf_d_suite());
  srunner_add_suite(sr, my_sscanf_x_X_suite());
  srunner_add_suite(sr, my_sscanf_o_suite());
  srunner_add_suite(sr, my_sscanf_i_suite());
  srunner_add_suite(sr, my_sscanf_u_suite());
  srunner_add_suite(sr, my_sscanf_c_suite());
  srunner_add_suite(sr, my_sscanf_s_suite());
  srunner_add_suite(sr, my_sscanf_f_suite());
  srunner_add_suite(sr, my_sscanf_F_suite());
  srunner_add_suite(sr, my_sscanf_e_suite());
  srunner_add_suite(sr, my_sscanf_E_suite());
  srunner_add_suite(sr, my_sscanf_g_suite());
  srunner_add_suite(sr, my_sscanf_G_suite());
  srunner_add_suite(sr, my_sscanf_n_suite());
  srunner_add_suite(sr, my_sscanf_percent_suite());
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}