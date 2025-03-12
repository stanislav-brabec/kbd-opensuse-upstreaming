#include "config.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libcommon.h"

void
print_version_and_exit(void)
{
	printf(_("%s from %s\n"), program_invocation_short_name, PACKAGE_STRING);
	exit(0);
}

void
print_options(const struct kbd_help *options)
{
	int max = 0;
	const struct kbd_help *h;

	if (!options)
		return;

	fprintf(stderr, "\n");
	fprintf(stderr, _("Options:"));
	fprintf(stderr, "\n");

	for (h = options; h && h->opts; h++) {
		int len = (int) strlen(h->opts);
		if (max < len)
			max = len;
	}
	max += 2;

	for (h = options; h && h->opts; h++)
		fprintf(stderr, "  %-*s %s\n", max, h->opts, h->desc);
}

void
print_report_bugs(void)
{
	fprintf(stderr, "\n");
	fprintf(stderr, _("Report bugs to authors.\n"));
	fprintf(stderr, "\n");
}
