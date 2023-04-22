package(default_visibility = ["//visibility:public"])

cc_library(
    name = "constants",
    hdrs = ["constants.h"],
)

cc_library(
    name = "utils",
    srcs = ["utils.cpp"],
    hdrs = ["utils.h"],
    deps = [
        ":constants"
    ]
)

cc_test(
    name = "utils_test",
    srcs = ["utils_test.cpp"],
    deps = ["@com_google_googletest//:gtest_main",
            ":utils"]
)
