#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>

typedef struct {
  ngx_str_t output_words;
}ngx_http_hello_nginx_loc_conf_t;

static char *ngx_http_hello_nginx(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
static void *ngx_http_hello_nginx_create_loc_conf(ngx_conf_t *cf);
static char *ngx_http_hello_nginx_merge_loc_conf(ngx_conf_t *cf, void *parent, void *child);

static ngx_command_t ngx_http_hello_nginx_commands[] = {
  {
    ngx_string("hello_nginx"),
    NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
    ngx_http_hello_nginx,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(ngx_http_hello_nginx_loc_conf_t, output_words),
    NULL
  },
  ngx_null_command,
};

u_char ngx_print[] = "Hello, my new Nginx";

static ngx_http_module_t ngx_http_hello_nginx_module_ctx = {
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  ngx_http_hello_nginx_create_loc_conf,
  ngx_http_hello_nginx_merge_loc_conf
};

ngx_module_t ngx_http_hello_nginx_module = {
  NGX_MODULE_V1,
  &ngx_http_hello_nginx_module_ctx,
  ngx_http_hello_nginx_commands,
  NGX_HTTP_MODULE,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NGX_MODULE_V1_PADDING
};

static ngx_int_t 
ngx_http_hello_nginx_handler(ngx_http_request_t *r){
  ngx_int_t rc;
  ngx_buf_t *b;
  ngx_chain_t out[2];
  ngx_http_hello_nginx_loc_conf_t *hlcf;
  
  hlcf = ngx_http_get_module_loc_conf(r, ngx_http_hello_nginx_module);/*get the current request' ctx*/

  r->headers_out.content_type.len = sizeof("text/plain") - 1;
  r->headers_out.content_type.data = (u_char*)"text/plain";

  b = ngx_pcalloc(r->pool, sizeof(ngx_buf_t));
  out[0].buf = b;
  out[0].next = &out[1];
  b->pos = (u_char*)ngx_print;
  b->last = b->pos + sizeof(ngx_print) - 1;
  b->memory = 1;

  b = ngx_pcalloc(r->pool, sizeof(ngx_buf_t));
  out[1].buf = b;
  out[1].next = NULL;
  b->pos = hlcf->output_words.data;
  b->last = hlcf->output_words.data + (hlcf->output_words.len);
  b->memory = 1;
  b->last_buf = 1;

  r->headers_out.status = NGX_HTTP_OK;
  r->headers_out.content_length_n = hlcf->output_words.len + sizeof(ngx_print) - 1;
  rc = ngx_http_send_header(r);

  if(rc == NGX_ERROR||rc > NGX_OK||r->header_only){
    return rc;
  }

  return ngx_http_output_filter(r, &out[0]);
}

static void *
ngx_http_hello_nginx_create_loc_conf(ngx_conf_t* cf){
  ngx_http_hello_nginx_loc_conf_t *conf;

  conf = ngx_pcalloc(cf->pool, sizeof(ngx_http_hello_nginx_loc_conf_t));
  if(conf==NULL){
    return NGX_CONF_ERROR;
  }
  conf->output_words.len = 0;
  conf->output_words.data = NULL;
  return conf;
}

static char *
ngx_http_hello_nginx_merge_loc_conf(ngx_conf_t *cf, void *parent, void *child){
  ngx_http_hello_nginx_loc_conf_t *prev = parent;
  ngx_http_hello_nginx_loc_conf_t *conf = child;

  ngx_conf_merge_str_value(conf->output_words, prev->output_words, "Nginx");

  return NGX_CONF_OK;
}

static char *
ngx_http_hello_nginx(ngx_conf_t *cf, ngx_command_t *cmd, void *conf){
  ngx_http_core_loc_conf_t *clcf;

  clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
  clcf->handler = ngx_http_hello_nginx_handler;

  ngx_conf_set_str_slot(cf, cmd, conf);

  return NGX_CONF_OK;
}
