#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6bb013d4, "get_user_pages_fast" },
	{ 0xa61fd7aa, "__check_object_size" },
	{ 0xd272d446, "rtnl_unlock" },
	{ 0x0040afbe, "param_ops_uint" },
	{ 0x092a35a2, "_copy_from_user" },
	{ 0x18d43ede, "skb_put" },
	{ 0xd272d446, "__rcu_read_lock" },
	{ 0xd710adbf, "__kmalloc_noprof" },
	{ 0x747bd2f7, "consume_skb" },
	{ 0x20fe0e51, "csum_partial" },
	{ 0x4a44cce3, "dev_add_pack" },
	{ 0x7db71bea, "unregister_netdev" },
	{ 0x74f8d140, "skb_dequeue" },
	{ 0xc87f4bab, "finish_wait" },
	{ 0xa53f4e29, "memcpy" },
	{ 0xcb8b6ec6, "kfree" },
	{ 0xd3fe49f6, "dev_set_promiscuity" },
	{ 0xc87f4bab, "add_wait_queue" },
	{ 0x0db8d68d, "prepare_to_wait_event" },
	{ 0x84bf91d8, "iov_iter_init" },
	{ 0x16ab4215, "__wake_up" },
	{ 0x02e1dca7, "free_pages" },
	{ 0x37197a78, "vsnprintf" },
	{ 0xe1e1f979, "_raw_spin_lock_irqsave" },
	{ 0xde338d9a, "_raw_spin_lock" },
	{ 0x6530c929, "__dev_get_by_name" },
	{ 0xb69d5d49, "ether_setup" },
	{ 0xd272d446, "__fentry__" },
	{ 0xa5d4e4fb, "dev_addr_mod" },
	{ 0xe59bea4d, "eth_type_trans" },
	{ 0x5a844b26, "__x86_indirect_thunk_rax" },
	{ 0x82872ec5, "alloc_netdev_mqs" },
	{ 0xe8213e80, "_printk" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0xd272d446, "schedule" },
	{ 0x5a8347fe, "__tracepoint_sched_set_state_tp" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0x2520ea93, "refcount_warn_saturate" },
	{ 0xd272d446, "__put_user_4" },
	{ 0x0c161ddc, "capable" },
	{ 0x90a48d82, "__ubsan_handle_out_of_bounds" },
	{ 0xbd03ed67, "page_offset_base" },
	{ 0x44decd6f, "hugetlb_optimize_vmemmap_key" },
	{ 0x7a5ffe84, "init_wait_entry" },
	{ 0x7d240728, "init_net" },
	{ 0xd272d446, "__rcu_read_unlock" },
	{ 0xee3afd5d, "sk_skb_reason_drop" },
	{ 0x4a44cce3, "dev_remove_pack" },
	{ 0x8ba052c7, "sk_free" },
	{ 0xbd03ed67, "random_kmalloc_seed" },
	{ 0xf46d5bf3, "mutex_lock" },
	{ 0x18d43ede, "skb_push" },
	{ 0x2719b9fa, "const_current_task" },
	{ 0x2f2f45a5, "register_netdev" },
	{ 0x5a844b26, "__x86_indirect_thunk_r13" },
	{ 0x7db71bea, "free_netdev" },
	{ 0x9e3a8e47, "_raw_read_unlock" },
	{ 0x402db74e, "memcmp" },
	{ 0x682cbb11, "skb_copy_datagram_iter" },
	{ 0xe54e0a6b, "__fortify_panic" },
	{ 0x81a1a811, "_raw_spin_unlock_irqrestore" },
	{ 0xe067f7eb, "sk_alloc" },
	{ 0x89b04984, "proc_mkdir" },
	{ 0x27683a56, "memset" },
	{ 0x5a844b26, "__x86_indirect_thunk_r10" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0x2247bd2b, "default_wake_function" },
	{ 0x092a35a2, "_copy_to_user" },
	{ 0x5403c125, "__init_waitqueue_head" },
	{ 0x4124c2d0, "__pskb_pull_tail" },
	{ 0xa97ffed0, "netif_rx" },
	{ 0x94708fba, "__netdev_alloc_skb" },
	{ 0x102ef4a9, "proc_remove" },
	{ 0xc7ca1fbd, "_raw_write_unlock_irqrestore" },
	{ 0x888b8f57, "strcmp" },
	{ 0xfd285498, "unregister_netdevice_notifier" },
	{ 0x058c185a, "jiffies" },
	{ 0xdd6830c7, "sprintf" },
	{ 0xbd03ed67, "vmemmap_base" },
	{ 0x70193767, "__dev_queue_xmit" },
	{ 0x8d42f73c, "skb_set_owner_w" },
	{ 0xf46d5bf3, "mutex_unlock" },
	{ 0x5a844b26, "__x86_indirect_thunk_rcx" },
	{ 0x37031a65, "__register_chrdev" },
	{ 0x1d4ead48, "__folio_put" },
	{ 0x7851be11, "__get_user_4" },
	{ 0xc064623f, "__kmalloc_cache_noprof" },
	{ 0x546c19d9, "validate_usercopy_range" },
	{ 0x75738bed, "__warn_printk" },
	{ 0xfd285498, "register_netdevice_notifier" },
	{ 0xb61837ba, "seq_printf" },
	{ 0x6ab80e94, "skb_copy" },
	{ 0xfb3bad2b, "skb_clone" },
	{ 0x9e3a8e47, "_raw_read_lock" },
	{ 0xd272d446, "rtnl_lock" },
	{ 0xc87f4bab, "remove_wait_queue" },
	{ 0x530282a0, "proc_create_single_data" },
	{ 0x78bbf245, "_raw_write_lock_irqsave" },
	{ 0xe4de56b4, "__ubsan_handle_load_invalid_value" },
	{ 0xde338d9a, "_raw_spin_unlock" },
	{ 0x6bded543, "get_free_pages_noprof" },
	{ 0x986d7c37, "__skb_gso_segment" },
	{ 0x5a844b26, "__x86_indirect_thunk_r8" },
	{ 0x6bf1dd2b, "sock_init_data" },
	{ 0x7851be11, "__SCT__might_resched" },
	{ 0xfaabfe5e, "kmalloc_caches" },
	{ 0xb2e62cba, "__trace_set_current_state" },
	{ 0x52b15b3b, "__unregister_chrdev" },
	{ 0xbebe66ff, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x6bb013d4,
	0xa61fd7aa,
	0xd272d446,
	0x0040afbe,
	0x092a35a2,
	0x18d43ede,
	0xd272d446,
	0xd710adbf,
	0x747bd2f7,
	0x20fe0e51,
	0x4a44cce3,
	0x7db71bea,
	0x74f8d140,
	0xc87f4bab,
	0xa53f4e29,
	0xcb8b6ec6,
	0xd3fe49f6,
	0xc87f4bab,
	0x0db8d68d,
	0x84bf91d8,
	0x16ab4215,
	0x02e1dca7,
	0x37197a78,
	0xe1e1f979,
	0xde338d9a,
	0x6530c929,
	0xb69d5d49,
	0xd272d446,
	0xa5d4e4fb,
	0xe59bea4d,
	0x5a844b26,
	0x82872ec5,
	0xe8213e80,
	0xbd03ed67,
	0xd272d446,
	0x5a8347fe,
	0xd272d446,
	0x2520ea93,
	0xd272d446,
	0x0c161ddc,
	0x90a48d82,
	0xbd03ed67,
	0x44decd6f,
	0x7a5ffe84,
	0x7d240728,
	0xd272d446,
	0xee3afd5d,
	0x4a44cce3,
	0x8ba052c7,
	0xbd03ed67,
	0xf46d5bf3,
	0x18d43ede,
	0x2719b9fa,
	0x2f2f45a5,
	0x5a844b26,
	0x7db71bea,
	0x9e3a8e47,
	0x402db74e,
	0x682cbb11,
	0xe54e0a6b,
	0x81a1a811,
	0xe067f7eb,
	0x89b04984,
	0x27683a56,
	0x5a844b26,
	0xd272d446,
	0x2247bd2b,
	0x092a35a2,
	0x5403c125,
	0x4124c2d0,
	0xa97ffed0,
	0x94708fba,
	0x102ef4a9,
	0xc7ca1fbd,
	0x888b8f57,
	0xfd285498,
	0x058c185a,
	0xdd6830c7,
	0xbd03ed67,
	0x70193767,
	0x8d42f73c,
	0xf46d5bf3,
	0x5a844b26,
	0x37031a65,
	0x1d4ead48,
	0x7851be11,
	0xc064623f,
	0x546c19d9,
	0x75738bed,
	0xfd285498,
	0xb61837ba,
	0x6ab80e94,
	0xfb3bad2b,
	0x9e3a8e47,
	0xd272d446,
	0xc87f4bab,
	0x530282a0,
	0x78bbf245,
	0xe4de56b4,
	0xde338d9a,
	0x6bded543,
	0x986d7c37,
	0x5a844b26,
	0x6bf1dd2b,
	0x7851be11,
	0xfaabfe5e,
	0xb2e62cba,
	0x52b15b3b,
	0xbebe66ff,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"get_user_pages_fast\0"
	"__check_object_size\0"
	"rtnl_unlock\0"
	"param_ops_uint\0"
	"_copy_from_user\0"
	"skb_put\0"
	"__rcu_read_lock\0"
	"__kmalloc_noprof\0"
	"consume_skb\0"
	"csum_partial\0"
	"dev_add_pack\0"
	"unregister_netdev\0"
	"skb_dequeue\0"
	"finish_wait\0"
	"memcpy\0"
	"kfree\0"
	"dev_set_promiscuity\0"
	"add_wait_queue\0"
	"prepare_to_wait_event\0"
	"iov_iter_init\0"
	"__wake_up\0"
	"free_pages\0"
	"vsnprintf\0"
	"_raw_spin_lock_irqsave\0"
	"_raw_spin_lock\0"
	"__dev_get_by_name\0"
	"ether_setup\0"
	"__fentry__\0"
	"dev_addr_mod\0"
	"eth_type_trans\0"
	"__x86_indirect_thunk_rax\0"
	"alloc_netdev_mqs\0"
	"_printk\0"
	"__ref_stack_chk_guard\0"
	"schedule\0"
	"__tracepoint_sched_set_state_tp\0"
	"__stack_chk_fail\0"
	"refcount_warn_saturate\0"
	"__put_user_4\0"
	"capable\0"
	"__ubsan_handle_out_of_bounds\0"
	"page_offset_base\0"
	"hugetlb_optimize_vmemmap_key\0"
	"init_wait_entry\0"
	"init_net\0"
	"__rcu_read_unlock\0"
	"sk_skb_reason_drop\0"
	"dev_remove_pack\0"
	"sk_free\0"
	"random_kmalloc_seed\0"
	"mutex_lock\0"
	"skb_push\0"
	"const_current_task\0"
	"register_netdev\0"
	"__x86_indirect_thunk_r13\0"
	"free_netdev\0"
	"_raw_read_unlock\0"
	"memcmp\0"
	"skb_copy_datagram_iter\0"
	"__fortify_panic\0"
	"_raw_spin_unlock_irqrestore\0"
	"sk_alloc\0"
	"proc_mkdir\0"
	"memset\0"
	"__x86_indirect_thunk_r10\0"
	"__x86_return_thunk\0"
	"default_wake_function\0"
	"_copy_to_user\0"
	"__init_waitqueue_head\0"
	"__pskb_pull_tail\0"
	"netif_rx\0"
	"__netdev_alloc_skb\0"
	"proc_remove\0"
	"_raw_write_unlock_irqrestore\0"
	"strcmp\0"
	"unregister_netdevice_notifier\0"
	"jiffies\0"
	"sprintf\0"
	"vmemmap_base\0"
	"__dev_queue_xmit\0"
	"skb_set_owner_w\0"
	"mutex_unlock\0"
	"__x86_indirect_thunk_rcx\0"
	"__register_chrdev\0"
	"__folio_put\0"
	"__get_user_4\0"
	"__kmalloc_cache_noprof\0"
	"validate_usercopy_range\0"
	"__warn_printk\0"
	"register_netdevice_notifier\0"
	"seq_printf\0"
	"skb_copy\0"
	"skb_clone\0"
	"_raw_read_lock\0"
	"rtnl_lock\0"
	"remove_wait_queue\0"
	"proc_create_single_data\0"
	"_raw_write_lock_irqsave\0"
	"__ubsan_handle_load_invalid_value\0"
	"_raw_spin_unlock\0"
	"get_free_pages_noprof\0"
	"__skb_gso_segment\0"
	"__x86_indirect_thunk_r8\0"
	"sock_init_data\0"
	"__SCT__might_resched\0"
	"kmalloc_caches\0"
	"__trace_set_current_state\0"
	"__unregister_chrdev\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "3721B38D7BEAF06ABDC69E2");
