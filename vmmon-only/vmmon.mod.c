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
	{ 0x1bdf2bc8, "sme_me_mask" },
	{ 0x6bb013d4, "get_user_pages_fast" },
	{ 0xb6a67cd6, "smp_call_function_single" },
	{ 0xa61fd7aa, "__check_object_size" },
	{ 0xdb5c5ac9, "__init_rwsem" },
	{ 0xd5ad82a1, "misc_deregister" },
	{ 0x092a35a2, "_copy_from_user" },
	{ 0x2182515b, "__num_online_cpus" },
	{ 0xd710adbf, "__kmalloc_noprof" },
	{ 0x26a25e1b, "vmalloc_to_page" },
	{ 0xd272d446, "__SCT__preempt_schedule" },
	{ 0xbd03ed67, "this_cpu_off" },
	{ 0x71e989ee, "fget" },
	{ 0x4073d0de, "up" },
	{ 0xb2fa43dd, "kernel_sigaction" },
	{ 0xa53f4e29, "memcpy" },
	{ 0xf1de9e85, "vunmap" },
	{ 0x9f2f63a9, "smp_ops" },
	{ 0xcb8b6ec6, "kfree" },
	{ 0x86693e87, "schedule_hrtimeout_range" },
	{ 0x5e505530, "kthread_should_stop" },
	{ 0x2352b148, "timer_delete_sync" },
	{ 0x02e1dca7, "free_pages" },
	{ 0x37197a78, "vsnprintf" },
	{ 0x5723059f, "msleep_interruptible" },
	{ 0xd272d446, "__fentry__" },
	{ 0x630dad60, "wake_up_process" },
	{ 0x5a844b26, "__x86_indirect_thunk_rax" },
	{ 0xe8213e80, "_printk" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0x6ac784f4, "schedule_timeout" },
	{ 0xd272d446, "schedule" },
	{ 0x5a8347fe, "__tracepoint_sched_set_state_tp" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0xf296206e, "cpu_khz" },
	{ 0x8a7140c6, "smp_call_function" },
	{ 0x5a844b26, "__x86_indirect_thunk_rdx" },
	{ 0xcf119e7a, "__free_pages" },
	{ 0x1b60315e, "copy_from_kernel_nofault" },
	{ 0x90a48d82, "__ubsan_handle_out_of_bounds" },
	{ 0xbd03ed67, "page_offset_base" },
	{ 0x44decd6f, "hugetlb_optimize_vmemmap_key" },
	{ 0xf3adfcd9, "poll_initwait" },
	{ 0x8fd1737a, "fput" },
	{ 0xa59da3c0, "down_write" },
	{ 0xa59da3c0, "up_write" },
	{ 0xa470b7e2, "add_timer" },
	{ 0xf3adfcd9, "poll_freewait" },
	{ 0x32feeafc, "mod_timer" },
	{ 0x4073d0de, "down" },
	{ 0xbd03ed67, "random_kmalloc_seed" },
	{ 0xd7a59a65, "vmalloc_noprof" },
	{ 0x5a844b26, "__x86_indirect_thunk_rbx" },
	{ 0x2719b9fa, "const_current_task" },
	{ 0xbd03ed67, "phys_base" },
	{ 0x03b55e57, "vmap" },
	{ 0x680628e7, "ktime_get_raw_ts64" },
	{ 0xf654f750, "_totalram_pages" },
	{ 0x0571dc46, "kthread_stop" },
	{ 0xa2c25da9, "vmalloc_to_pfn" },
	{ 0x5fc55113, "__default_kernel_pte_mask" },
	{ 0x27683a56, "memset" },
	{ 0xaca12394, "misc_register" },
	{ 0x4b5cc7c5, "kernel_read" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0x092a35a2, "_copy_to_user" },
	{ 0x888b8f57, "strcmp" },
	{ 0xa59da3c0, "down_read" },
	{ 0x058c185a, "jiffies" },
	{ 0x7f79e79a, "kthread_create_on_node" },
	{ 0x6f8082dd, "pv_ops" },
	{ 0xbd03ed67, "vmemmap_base" },
	{ 0x82fd7238, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7ec472ba, "cpu_number" },
	{ 0x7ec472ba, "__preempt_count" },
	{ 0xf296206e, "tsc_khz" },
	{ 0x7851be11, "__get_user_1" },
	{ 0xf1de9e85, "vfree" },
	{ 0xd1724193, "vm_node_stat" },
	{ 0xdaaacee0, "get_user_pages_unlocked" },
	{ 0x1d4ead48, "__folio_put" },
	{ 0xc064623f, "__kmalloc_cache_noprof" },
	{ 0x546c19d9, "validate_usercopy_range" },
	{ 0x7851be11, "__SCT__cond_resched" },
	{ 0xc257fae0, "alloc_pages_noprof" },
	{ 0x02f9bbf0, "timer_init_key" },
	{ 0x5a844b26, "__x86_indirect_thunk_r12" },
	{ 0xa9d7de7c, "gdt_page" },
	{ 0x2e5844fe, "schedule_hrtimeout" },
	{ 0x6bded543, "get_free_pages_noprof" },
	{ 0xa59da3c0, "up_read" },
	{ 0xd272d446, "BUG_func" },
	{ 0x7851be11, "__SCT__might_resched" },
	{ 0xfaabfe5e, "kmalloc_caches" },
	{ 0xb2e62cba, "__trace_set_current_state" },
	{ 0xbebe66ff, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x1bdf2bc8,
	0x6bb013d4,
	0xb6a67cd6,
	0xa61fd7aa,
	0xdb5c5ac9,
	0xd5ad82a1,
	0x092a35a2,
	0x2182515b,
	0xd710adbf,
	0x26a25e1b,
	0xd272d446,
	0xbd03ed67,
	0x71e989ee,
	0x4073d0de,
	0xb2fa43dd,
	0xa53f4e29,
	0xf1de9e85,
	0x9f2f63a9,
	0xcb8b6ec6,
	0x86693e87,
	0x5e505530,
	0x2352b148,
	0x02e1dca7,
	0x37197a78,
	0x5723059f,
	0xd272d446,
	0x630dad60,
	0x5a844b26,
	0xe8213e80,
	0xbd03ed67,
	0x6ac784f4,
	0xd272d446,
	0x5a8347fe,
	0xd272d446,
	0xf296206e,
	0x8a7140c6,
	0x5a844b26,
	0xcf119e7a,
	0x1b60315e,
	0x90a48d82,
	0xbd03ed67,
	0x44decd6f,
	0xf3adfcd9,
	0x8fd1737a,
	0xa59da3c0,
	0xa59da3c0,
	0xa470b7e2,
	0xf3adfcd9,
	0x32feeafc,
	0x4073d0de,
	0xbd03ed67,
	0xd7a59a65,
	0x5a844b26,
	0x2719b9fa,
	0xbd03ed67,
	0x03b55e57,
	0x680628e7,
	0xf654f750,
	0x0571dc46,
	0xa2c25da9,
	0x5fc55113,
	0x27683a56,
	0xaca12394,
	0x4b5cc7c5,
	0xd272d446,
	0x092a35a2,
	0x888b8f57,
	0xa59da3c0,
	0x058c185a,
	0x7f79e79a,
	0x6f8082dd,
	0xbd03ed67,
	0x82fd7238,
	0x7ec472ba,
	0x7ec472ba,
	0xf296206e,
	0x7851be11,
	0xf1de9e85,
	0xd1724193,
	0xdaaacee0,
	0x1d4ead48,
	0xc064623f,
	0x546c19d9,
	0x7851be11,
	0xc257fae0,
	0x02f9bbf0,
	0x5a844b26,
	0xa9d7de7c,
	0x2e5844fe,
	0x6bded543,
	0xa59da3c0,
	0xd272d446,
	0x7851be11,
	0xfaabfe5e,
	0xb2e62cba,
	0xbebe66ff,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"sme_me_mask\0"
	"get_user_pages_fast\0"
	"smp_call_function_single\0"
	"__check_object_size\0"
	"__init_rwsem\0"
	"misc_deregister\0"
	"_copy_from_user\0"
	"__num_online_cpus\0"
	"__kmalloc_noprof\0"
	"vmalloc_to_page\0"
	"__SCT__preempt_schedule\0"
	"this_cpu_off\0"
	"fget\0"
	"up\0"
	"kernel_sigaction\0"
	"memcpy\0"
	"vunmap\0"
	"smp_ops\0"
	"kfree\0"
	"schedule_hrtimeout_range\0"
	"kthread_should_stop\0"
	"timer_delete_sync\0"
	"free_pages\0"
	"vsnprintf\0"
	"msleep_interruptible\0"
	"__fentry__\0"
	"wake_up_process\0"
	"__x86_indirect_thunk_rax\0"
	"_printk\0"
	"__ref_stack_chk_guard\0"
	"schedule_timeout\0"
	"schedule\0"
	"__tracepoint_sched_set_state_tp\0"
	"__stack_chk_fail\0"
	"cpu_khz\0"
	"smp_call_function\0"
	"__x86_indirect_thunk_rdx\0"
	"__free_pages\0"
	"copy_from_kernel_nofault\0"
	"__ubsan_handle_out_of_bounds\0"
	"page_offset_base\0"
	"hugetlb_optimize_vmemmap_key\0"
	"poll_initwait\0"
	"fput\0"
	"down_write\0"
	"up_write\0"
	"add_timer\0"
	"poll_freewait\0"
	"mod_timer\0"
	"down\0"
	"random_kmalloc_seed\0"
	"vmalloc_noprof\0"
	"__x86_indirect_thunk_rbx\0"
	"const_current_task\0"
	"phys_base\0"
	"vmap\0"
	"ktime_get_raw_ts64\0"
	"_totalram_pages\0"
	"kthread_stop\0"
	"vmalloc_to_pfn\0"
	"__default_kernel_pte_mask\0"
	"memset\0"
	"misc_register\0"
	"kernel_read\0"
	"__x86_return_thunk\0"
	"_copy_to_user\0"
	"strcmp\0"
	"down_read\0"
	"jiffies\0"
	"kthread_create_on_node\0"
	"pv_ops\0"
	"vmemmap_base\0"
	"__ubsan_handle_shift_out_of_bounds\0"
	"cpu_number\0"
	"__preempt_count\0"
	"tsc_khz\0"
	"__get_user_1\0"
	"vfree\0"
	"vm_node_stat\0"
	"get_user_pages_unlocked\0"
	"__folio_put\0"
	"__kmalloc_cache_noprof\0"
	"validate_usercopy_range\0"
	"__SCT__cond_resched\0"
	"alloc_pages_noprof\0"
	"timer_init_key\0"
	"__x86_indirect_thunk_r12\0"
	"gdt_page\0"
	"schedule_hrtimeout\0"
	"get_free_pages_noprof\0"
	"up_read\0"
	"BUG_func\0"
	"__SCT__might_resched\0"
	"kmalloc_caches\0"
	"__trace_set_current_state\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "3A524DEEF35BA38F5EAA036");
