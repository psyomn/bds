#include <bds/queue.h>
#include <bds/test.h>
#include <assert.h>

int insert_test(void** data)
{
  (void) data;
  struct bds_queue* q = bds_queue_new();

  bds_queue_enq(q, 1);
  bds_queue_enq(q, 2);
  bds_queue_enq(q, 3);

  assert(bds_queue_len(q) == 3);

  bds_queue_free(q);
  return 0;
}

int remove_test(void** data)
{
  (void) data;
  struct bds_queue* q = bds_queue_new();

  bds_queue_enq(q, 1);
  bds_queue_enq(q, 2);
  bds_queue_enq(q, 3);

  uint64_t a = bds_queue_deq(q),
    b = bds_queue_deq(q),
    c = bds_queue_deq(q);

  assert(a == 1);
  assert(b == 2);
  assert(c == 3);

  bds_queue_free(q);
  return 0;
}

int interleaved_op_test(void** data)
{
  (void) data;
  struct bds_queue* q = bds_queue_new();

  bds_queue_enq(q, 1);
  bds_queue_enq(q, 2);
  bds_queue_enq(q, 3);

  assert(bds_queue_deq(q) == 1);

  bds_queue_enq(q, 4);
  bds_queue_enq(q, 5);

  assert(bds_queue_len(q) == 4);

  bds_queue_free(q);
  return 0;
}

int big_enq_deq_test(void** data)
{
  (void) data;

  const size_t n = 1000000;
  struct bds_queue* q = bds_queue_new();

  for (size_t i = 0; i < n; ++i) {
    bds_queue_enq(q, i);
  }

  for (size_t i = 0; i < n; ++i) {
    assert(i == bds_queue_deq(q));
  }

  assert(0 == bds_queue_len(q));

  bds_queue_free(q);
  return 0;
}

int main(void)
{
  bds_test("test insert", insert_test, NULL);
  bds_test("test remove", remove_test, NULL);
  bds_test("interleave deq enq", interleaved_op_test, NULL);
  bds_test("big enq/deq test", big_enq_deq_test, NULL);
  return 0;
}
