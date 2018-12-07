#include "config.h"
#include <stdlib.h>

#include "cache/cache.h"
#include "vcl.h"

#include "vcc_test304_if.h"

VCL_BOOL
vmod_is_304(VRT_CTX)
{
	struct req *req;

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

	req = ctx->req;
	CHECK_OBJ_NOTNULL(req, REQ_MAGIC);

	if (ctx->method != VCL_MET_DELIVER) {
		VSLb(ctx->vsl, SLT_VCL_Error,
		    "vmod test304 can only be used in vcl_deliver {}");
		return (0);
	}

	return (!(req->objcore->flags & OC_F_HFP)
	    && req->esi_level == 0
	    && http_IsStatus(req->resp, 200)
	    && req->http->conds && RFC2616_Do_Cond(req));
}
