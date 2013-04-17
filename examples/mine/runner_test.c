#include <mruby.h>
#include <mruby/proc.h>
#include <mruby/string.h>
#include <mruby/compile.h>

#include <stdint.h>

// p 1 + 2
const uint8_t hoge[] = {
0x52,0x49,0x54,0x45,0x30,0x30,0x30,0x31,0xe1,0xd3,0x00,0x00,0x00,0x5e,0x4d,0x41,
0x54,0x5a,0x30,0x30,0x30,0x30,0x49,0x52,0x45,0x50,0x00,0x00,0x00,0x40,0x30,0x30,
0x30,0x30,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x01,0x00,0x04,0x00,0x00,
0x00,0x05,0x00,0x80,0x00,0x06,0x01,0x40,0x00,0x03,0x01,0x00,0x41,0x2d,0x00,0x80,
0x00,0xa0,0x00,0x00,0x00,0x4a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x01,
0x70,0x00,0x00,0x01,0x2b,0x00,0x45,0x4e,0x44,0x00,0x00,0x00,0x00,0x08,
};

int main(int argc, char* argv[])
{
  mrb_state* mrb = mrb_open();
  if(mrb != 0) {

    mrb_value return_value = mrb_load_irep(mrb, hoge);

    if(mrb->exc) {
      mrb_p(mrb, return_value);
      mrb->exc = 0;
    }
    mrb_close(mrb);
  } else {
    fprintf(stderr, "Failed to initialize");
  }

  return 0;
}
