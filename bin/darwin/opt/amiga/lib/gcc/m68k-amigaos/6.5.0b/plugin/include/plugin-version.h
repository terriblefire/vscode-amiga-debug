#include "configargs.h"

#define GCCPLUGIN_VERSION_MAJOR   6
#define GCCPLUGIN_VERSION_MINOR   5
#define GCCPLUGIN_VERSION_PATCHLEVEL   6.5.0b
#define GCCPLUGIN_VERSION  (GCCPLUGIN_VERSION_MAJOR*1000 + GCCPLUGIN_VERSION_MINOR)

static char basever[] = "6.5.0b";
static char datestamp[] = "220613185627";
static char devphase[] = "";
static char revision[] = "";

/* FIXME plugins: We should make the version information more precise.
   One way to do is to add a checksum. */

static struct plugin_gcc_version gcc_version = {basever, datestamp,
						devphase, revision,
						configuration_arguments};