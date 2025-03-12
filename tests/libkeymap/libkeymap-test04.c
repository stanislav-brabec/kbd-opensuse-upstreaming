#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <keymap.h>
#include "libcommon.h"

int
main(int argc KBD_ATTR_UNUSED, char **argv KBD_ATTR_UNUSED)
{
	struct lk_ctx *ctx;

	ctx = lk_init();

	if (ctx == NULL)
		kbd_error(EXIT_FAILURE, 0, "Unable to initialize structure by valid pointer");

	if (lk_free(ctx) != 0)
		kbd_error(EXIT_FAILURE, 0, "Unable to free by valid pointer");

	if (lk_free(NULL) == 0)
		kbd_error(EXIT_FAILURE, 0, "Possible to free NULL pointer");

	return EXIT_SUCCESS;
}
