check-criterion:
	@if ! test "$(criterion_objects)"; then \
		echo "[ERROR] Configure ecma_intl with --enable-criterion to run Criterion tests"; \
		echo "        To install Criterion, see https://github.com/Snaipe/Criterion"; \
		echo ""; \
		exit 1; \
	fi

tests/criterion/runner: check-criterion $(criterion_objects)
	$(CXX) $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -fprofile-arcs -ftest-coverage -O0 $(LDFLAGS) $(EXTRA_LDFLAGS) $(criterion_objects) -o tests/criterion/runner $(ECMA_INTL_SHARED_LIBADD) $(CRITERION_LIBS)

#
# In CLion, set the "Build target" to "dev" in the Makefile project settings,
# and CLion will provide proper source code insight for code in both the src/
# and tests/ directories, since we're including "all" and
# "tests/criterion/runner" in this target.
#
# See: https://www.jetbrains.com/help/clion/makefiles-support.html#makefile-settings
#
dev: all tests/criterion/runner

criterion: tests/criterion/runner
	./tests/criterion/runner --color=always

criterion-clean:
	find . -name \*.d | xargs rm -f

gcov-clean:
	find . -name \*.gcda -name \*.gcno | xargs rm -f

clean: criterion-clean gcov-clean

.PHONY: check-criterion criterion criterion-clean
