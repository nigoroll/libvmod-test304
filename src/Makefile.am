AM_CFLAGS = $(VARNISHAPI_CFLAGS) -Wall -Werror
AM_LDFLAGS = $(VARNISHAPI_LIBS) $(VMOD_LDFLAGS) $(CODE_COVERAGE_LDFLAGS)

vmod_LTLIBRARIES = libvmod_test304.la

libvmod_test304_la_SOURCES = \
	vmod_test304.c

nodist_libvmod_test304_la_SOURCES = \
	vcc_test304_if.c \
	vcc_test304_if.h

dist_man_MANS = vmod_test304.3

@BUILD_VMOD_TEST304@

AM_TESTS_ENVIRONMENT = \
	PATH="$(VMOD_TEST_PATH)" \
	LD_LIBRARY_PATH="$(VARNISH_LIBRARY_PATH)"
TEST_EXTENSIONS = .vtc
VTC_LOG_COMPILER = varnishtest -v
AM_VTC_LOG_FLAGS = -Dvmod_test304="$(VMOD_TEST304)"

TESTS = @VMOD_TESTS@

EXTRA_DIST = \
	vmod_test304.vcc \
	$(VMOD_TESTS)
